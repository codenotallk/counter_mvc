#include <counter.h>
#include <string.h>

bool counter_init (counter_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (counter_t));

        status = true;
    }

    return status;
}

bool counter_get (counter_t *object, uint64_t *value)
{
    bool status = false;

    if (object != NULL && value != NULL)
    {
        *value = object->value;

        status = true;
    }

    return status;
}