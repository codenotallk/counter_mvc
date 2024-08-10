#include <counter_repository.h>
#include <string.h>

bool counter_repository_save (counter_repository_t *object, counter_t counter)
{
    bool status = false;

    if (object != NULL)
    {
        object->counter = counter;

        status = true;
    }

    return status;
}

bool counter_repository_get (counter_repository_t *object, counter_t *counter)
{
    bool status = false;

    if (object != NULL && counter != NULL)
    {
        counter_init (counter);

        *counter = object->counter;

        status = true;
    }

    return status;
}