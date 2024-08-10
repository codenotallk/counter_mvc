#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <sat.h>
#include <counter_repository.h>

#define CONTROLLER_BUFFER_SIZE  1024

typedef struct 
{
    sat_udp_t udp;
    char buffer [CONTROLLER_BUFFER_SIZE];
    counter_repository_t *repository;
} controller_t;

typedef struct 
{
    char *port;
    counter_repository_t *repository;
} controller_args_t;

bool controller_init (controller_t *object);
bool controller_open (controller_t *object, controller_args_t *args);
bool controller_run (controller_t *object);

#endif/* CONTROLLER_H_ */
