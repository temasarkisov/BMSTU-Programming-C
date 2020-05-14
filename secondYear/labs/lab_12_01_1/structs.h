#ifndef __STRUCTS_H__
#define __STRUCTS_H__

#include <stdint.h>
typedef struct polynom_node
{
    int32_t factor;
    int32_t power;
    struct polynom_node *next_node;
} polynom_node_t;

typedef struct
{
    int32_t size;
    polynom_node_t *head;
} polynom_t;

#endif