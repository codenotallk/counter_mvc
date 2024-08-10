#ifndef COUNTER_OUTPUT_H_
#define COUNTER_OUTPUT_H_

#include <counter.h>

typedef struct 
{
    uint64_t value;
} counter_output_t;

bool counter_output_from (counter_output_t *object, counter_t counter);

#endif/* COUNTER_OUTPUT_H_ */
