#include <controller.h>
#include <counter_json.h>
#include <counter_output.h>
#include <string.h>
#include <unistd.h>

#define CONTROLLER_INTERVAL     10
#define CONTROLLER_TIMEOUT      1000
#define CONTROLLER_STEP         1

static void controller_counter (void *object);

bool controller_init (controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (controller_t));

        status = true;
    }

    return status;
}

bool controller_open (controller_t *object, controller_args_t *args)
{
    bool status = false;
    sat_status_t __status;

    if (object != NULL && args != NULL)
    {
        do
        {
            __status = sat_udp_open (&object->udp, &(sat_udp_args_t)
                                                   {
                                                    .hostname = args->hostname,
                                                    .port = args->port,
                                                    .type = sat_udp_type_client
                                                   });

            if (sat_status_get_result (&__status) == false)
                break;

            __status = sat_scheduler_open (&object->scheduler, &(sat_scheduler_args_t)
                                                               {
                                                                .event_amount = 1
                                                               });

            if (sat_status_get_result (&__status) == false)
                break;

            __status = sat_scheduler_add_event (&object->scheduler, &(sat_scheduler_event_t)
                                                                    {
                                                                        .name = "counter",
                                                                        .object = object,
                                                                        .handler = controller_counter,
                                                                        .ran = false,
                                                                        .timeout = CONTROLLER_TIMEOUT
                                                                    });

            if (sat_status_get_result (&__status) == false)
                break;

            object->counter = args->counter;

            status = true;

        } while (false);

        status = true;
    }

    return status;
}

bool controller_run (controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        sat_scheduler_start (&object->scheduler);

        while (true)
        {
            usleep (CONTROLLER_INTERVAL);
        }

        status = true;
    }

    return status;
}

static void controller_counter (void *object)
{
    controller_t *controller = (controller_t *) object;

    counter_output_t output;
    counter_json_t json;
    char *json_str = NULL;

    counter_output_from (&output, *controller->counter);

    counter_json_serializer (&json, output);

    if (counter_json_get (&json, &json_str) == true)
    {
        sat_udp_send (&controller->udp, json_str, strlen (json_str));
    }

    counter_json_close (&json);

    counter_increment (controller->counter, CONTROLLER_STEP);
}