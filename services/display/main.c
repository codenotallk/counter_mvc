#include <controller.h>
#include <presenter.h>
#include <unistd.h>
#include <pthread.h>

static void *controller_thread_function (void *args);

int main (int argc, char *argv [])
{
    controller_t controller;
    presenter_t presenter;
    counter_repository_t repository;

    presenter_init (&presenter);
    controller_init (&controller);

    controller_open (&controller, &(controller_args_t)
                                  {
                                    .port = "1234",
                                    .repository = &repository
                                  });

    presenter_open (&presenter, &(presenter_args_t)
                                {
                                    .repository = &repository
                                });

    pthread_t controller_thread;

    pthread_create (&controller_thread, NULL, controller_thread_function, &controller);

    while (true)
    {
        presenter_show (&presenter);
        sleep (1);
    }

    return EXIT_SUCCESS;
}

static void *controller_thread_function (void *args)
{
    controller_t *controller = (controller_t *) args;

    controller_run (controller);

    return NULL;
}