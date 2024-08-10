#ifndef COUNTER_H_
#define COUNTER_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct 
{
    uint64_t value;
    bool initialized;
} counter_t;

bool counter_init (counter_t *object);
bool counter_increment (counter_t *object, uint64_t step);

#endif/* COUNTER_H_ */
