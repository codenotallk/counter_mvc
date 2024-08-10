#ifndef COUNTER_INPUT_H_
#define COUNTER_INPUT_H_

#include <counter.h>

typedef struct 
{
    uint64_t value;
} counter_input_t;

bool counter_input_to (counter_input_t *object, counter_t *counter);

#endif/* COUNTER_INPUT_H_ */
