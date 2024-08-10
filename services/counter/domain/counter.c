#include <counter.h>
#include <string.h>

bool counter_init (counter_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (counter_t));

        object->initialized = true;

        status = true;
    }

    return status;
}

bool counter_increment (counter_t *object, uint64_t step)
{
    bool status = false;

    if (object != NULL && object->initialized == true)
    {
        object->value += step;

        status = true;
    }

    return status;
}