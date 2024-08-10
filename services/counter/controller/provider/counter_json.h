#ifndef COUNTER_JSON_H_
#define COUNTER_JSON_H_

#include <counter_output.h>
#include <sat.h>

#define COUNTER_JSON_BUFFER_SIZE        1024

typedef struct 
{
    sat_json_t root;
    char buffer [COUNTER_JSON_BUFFER_SIZE];
} counter_json_t;

bool counter_json_serializer (counter_json_t *object, counter_output_t output);
bool counter_json_get (counter_json_t *object, char **json);
bool counter_json_close (counter_json_t *object);

#endif/* COUNTER_JSON_H_ */
