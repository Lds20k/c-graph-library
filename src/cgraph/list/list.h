#ifndef LIST_H
#define LIST_H
#include <stdlib.h>
#include <stdbool.h>
#include "../data/data.h"
#include "../node/node.h"

typedef struct list_s
{
    size_t length;
    node_t* start;
    node_t* end;
} list_t;

static const size_t SIZE_OF_LIST = sizeof(list_t);

list_t* create_list();
void destroy_list(list_t* list);
bool add_to_list(list_t* list, char* content_type, size_t content_size, void* content);
data_t* get_from_list(list_t* list, unsigned long index);

#endif