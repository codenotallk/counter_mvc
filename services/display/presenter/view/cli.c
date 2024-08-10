#include <cli.h>
#include <stdio.h>

bool cli_show (counter_representation_t *counter)
{
    bool status = false;

    if (counter != NULL)
    {
        printf ("Value: %ld\n", counter->value);

        status = true;
    }

    return status;
}