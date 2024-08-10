#ifndef PRESENTER_H_
#define PRESENTER_H_

#include <counter_repository.h>

typedef struct 
{
    counter_repository_t *repository;
} presenter_t;

typedef struct 
{
    counter_repository_t *repository;
} presenter_args_t;

bool presenter_init (presenter_t *object);
bool presenter_open (presenter_t *object, presenter_args_t *args);
bool presenter_show (presenter_t *object);

#endif/* PRESENTER_H_ */
