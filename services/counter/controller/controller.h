#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <counter.h>
#include <sat.h>

typedef struct 
{
    sat_udp_t udp;
    sat_scheduler_t scheduler;
    counter_t *counter;
} controller_t;

typedef struct 
{
    counter_t *counter;
    char *hostname;
    char *port;    
} controller_args_t;

bool controller_init (controller_t *object);
bool controller_open (controller_t *object, controller_args_t *args);
bool controller_run (controller_t *object);

#endif/* CONTROLLER_H_ */
