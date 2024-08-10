#ifndef COUNTER_JSON_H_
#define COUNTER_JSON_H_

#include <counter_input.h>
#include <sat.h>

typedef struct 
{
    sat_json_t root;
} counter_json_t;

bool counter_json_deserializer (counter_json_t *object, const char *json, counter_input_t *input);

#endif/* COUNTER_JSON_H_ */
