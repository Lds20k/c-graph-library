#include "list.h"

list_t* create_list(){
    list_t* new_list = (list_t*) calloc(1, SIZE_OF_LIST);
    return (new_list == NULL)? NULL : new_list;
}

void destroy_list(list_t* list){
    for (size_t i = 0; i < list->length; i++)
    {
        node_t* next_node = list->start->edges;
        list->start->edges_size = 0;
        destroy_node(list->start);
        list->start = next_node;
    }
    list->length = 0;

    free(list);
}

bool add_to_list(list_t* list, char* content_type, size_t content_size, void* content){
    node_t* new_node = create_node(content_type, content_size, content);
    if(new_node == NULL) return true;

    if (list->start == NULL) list->start = list->end = new_node;
    else{
        node_t* end_node = list->end;
        end_node->edges_size++;
        end_node->edges = new_node;
        list->end = new_node;
    }

    list->length++;
    return false;
}

data_t* get_from_list(list_t* list, unsigned long index){
    if(index >= list->length) return NULL;
    
    node_t* next_node = list->start;
    for (size_t i = 0; i < index; i++) next_node = next_node->edges;
    return next_node->data;
}