#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <controller.h>

int main (int argc, char *argv [])
{
    counter_t counter;
    controller_t controller;

    counter_init (&counter);
    controller_init (&controller);

    controller_open (&controller, &(controller_args_t)
                                  {
                                    .counter = &counter,
                                    .hostname = "localhost",
                                    .port = "1234"
                                  });

    controller_run (&controller);

    return EXIT_SUCCESS;
}
