#include <string.h>
#include "node.h"

node_t* create_node(char* content_type, size_t content_size, void* content){
    node_t* new_node = (node_t*) calloc(1, SIZE_OF_NODE);
    if (new_node == NULL) return NULL;
    
    data_t* new_data = create_data(content_type, content_size, content);
    if (new_node == NULL) {
        free(new_node);
        return NULL;
    }
    
    new_node->data = new_data;
    return new_node;
}

void destroy_node(node_t* node){
    destroy_data(node->data);
    node->edges_size = 0;
    free(node);
}