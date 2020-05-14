#ifndef __STRUCTS_H__
#define __STRUCTS_H__

typedef struct sts_node
{
    char *word;
    struct sts_node *next;
} sts_node_t;

typedef struct
{
    int size;
    sts_node_t *head;
} sts_t;

#endif
