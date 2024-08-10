#ifndef COUNTER_REPRESENTATION_H_
#define COUNTER_REPRESENTATION_H_

#include <counter.h>

typedef struct 
{
    uint64_t value;
} counter_representation_t;

bool counter_representation_from (counter_representation_t *object, counter_t counter);

#endif/* COUNTER_REPRESENTATION_H_ */
