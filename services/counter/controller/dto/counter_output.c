#include <counter_output.h>
#include <string.h>

bool counter_output_from (counter_output_t *object, counter_t counter)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (counter_output_t));

        object->value = counter.value;

        status = true;
    }

    return status;
}