#include <counter_json.h>
#include <string.h>

bool counter_json_deserializer (counter_json_t *object, const char *json, counter_input_t *input)
{
    bool status = false;

    if (object != NULL && json != NULL && input != NULL)
    {
        memset (input, 0, sizeof (counter_input_t));

        sat_json_mapper_t counter_mapper [] =
        {
            {.token = "counter", .data = &input->value, .type = sat_json_type_int, .size = sizeof (uint64_t)}
        };

        sat_json_deserialize (&object->root, json, counter_mapper, 1);

        status = true;
    }

    return status;
}