#include <counter_json.h>
#include <string.h>

bool counter_json_serializer (counter_json_t *object, counter_output_t output)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (counter_json_t));

        sat_json_open (&object->root, &(sat_json_args_t)
                                      {
                                        .buffer = object->buffer,
                                        .size = COUNTER_JSON_BUFFER_SIZE
                                      });

        sat_json_serialize_create_object (&object->root);

        sat_json_serialize_add (&object->root,
                                sat_json_type_int,
                                "counter",
                                &output.value);

        status = true;
    }

    return status;
}

bool counter_json_get (counter_json_t *object, char **json)
{
    bool status = false;

    if (object != NULL && json !=NULL)
    {
        sat_json_to_string (&object->root, json);

        status = true;
    }

    return status;
}

bool counter_json_close (counter_json_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        sat_json_close (&object->root);

        status = true;
    }

    return status;
}