#include <controller.h>
#include <string.h>
#include <counter_input.h>
#include <counter_json.h>

static void controller_on_receive (char *buffer, uint32_t *size, void *data);

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

    if (object != NULL && args != NULL && args->port != NULL && args->repository != NULL)
    {
        object->repository = args->repository;

        __status = sat_udp_open (&object->udp, &(sat_udp_args_t)
                                               {
                                                .type = sat_udp_type_server,
                                                .port = args->port,
                                                .buffer = object->buffer,
                                                .size = CONTROLLER_BUFFER_SIZE,
                                                .events = 
                                                {
                                                    .on_receive = controller_on_receive,
                                                },
                                                .data = object
                                               });
        if (sat_status_get_result (&__status) == false)
            status = true;
    }

    return status;
}

bool controller_run (controller_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        sat_udp_run (&object->udp);

        status = true;
    }

    return status;
}

static void controller_on_receive (char *buffer, uint32_t *size, void *data)
{
    controller_t *controller = (controller_t *) data;

    counter_json_t counter_json;
    counter_input_t input;
    counter_t counter;

    counter_json_deserializer (&counter_json, buffer, &input);
    counter_input_to (&input, &counter);

    counter_repository_save (controller->repository, counter);
}