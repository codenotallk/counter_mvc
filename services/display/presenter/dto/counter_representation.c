#include <counter_representation.h>
#include <string.h>

bool counter_representation_from (counter_representation_t *object, counter_t counter)
{
    bool status = false;

    if (object != NULL)
    {
        counter_get (&counter, &object->value);

        status = true;
    }

    return status;
}