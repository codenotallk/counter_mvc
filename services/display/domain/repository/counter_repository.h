#ifndef COUNTER_REPOSITORY_H_
#define COUNTER_REPOSITORY_H_

#include <counter.h>

typedef struct 
{
    counter_t counter;
} counter_repository_t;

bool counter_repository_save (counter_repository_t *object, counter_t counter);
bool counter_repository_get (counter_repository_t *object, counter_t *counter);

#endif/* COUNTER_REPOSITORY_H_ */
