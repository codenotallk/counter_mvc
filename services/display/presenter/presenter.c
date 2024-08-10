#include <presenter.h>
#include <string.h>
#include <stdio.h>
#include <cli.h>

bool presenter_init (presenter_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        memset (object, 0, sizeof (presenter_t));

        status = true;
    }

    return status;
}

bool presenter_open (presenter_t *object, presenter_args_t *args)
{
    bool status = false;

    if (object != NULL && args != NULL && args->repository != NULL)
    {
        object->repository = args->repository;

        status = true;
    }

    return status;
}

bool presenter_show (presenter_t *object)
{
    bool status = false;

    if (object != NULL)
    {
        counter_t counter;
        counter_representation_t representation;

        counter_repository_get (object->repository, &counter);
        counter_representation_from (&representation, counter);

        cli_show (&representation);
        
        status = true;
    }

    return status;
}