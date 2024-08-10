#ifndef COUNTER_H_
#define COUNTER_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct 
{
    uint64_t value;
} counter_t;

bool counter_init (counter_t *object);
bool counter_get (counter_t *object, uint64_t *value);

#endif/* COUNTER_H_ */

