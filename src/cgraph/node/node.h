#ifndef NODE_H
#define NODE_H
#include "../data/data.h"

typedef struct node_s node_t;
typedef struct node_s
{
    data_t* data;
    node_t* edges;
    size_t edges_size;
} node_t;

static const size_t SIZE_OF_NODE = sizeof(node_t);

node_t* create_node(char* content_type, size_t content_size, void* content);
void destroy_node(node_t* node);

#endif