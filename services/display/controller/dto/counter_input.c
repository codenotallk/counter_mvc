#include <counter_input.h>
#include <string.h>

bool counter_input_to (counter_input_t *object, counter_t *counter)
{
    bool status = false;

    if (object != NULL && counter != NULL)
    {
        counter->value = object->value;

        status = true;
    }

    return status;
}