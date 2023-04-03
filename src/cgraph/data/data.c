#include <string.h>
#include "data.h"

data_t* create_data(char* content_type, size_t content_size, void* content){
    data_t* new_data = (data_t*) calloc(1, SIZE_OF_DATA);
    if (new_data == NULL) return NULL;

    new_data->data_type = (char*) calloc(1, strlen(content_type) + 1);
    if(new_data->data_type == NULL){
        free(new_data);
        return NULL;
    }
    strcpy(new_data->data_type, content_type);

    new_data->data = (char*) calloc(1, content_size);
    if(new_data->data == NULL){
        free(new_data->data_type);
        free(new_data);
        return NULL;
    }
    memcpy(new_data->data, content, content_size);

    new_data->data_size = content_size;
    
    return new_data;
}

void destroy_data_content(data_t* data){
    free(data->data);
    free(data->data_type);
}

void destroy_data(data_t* data){
    destroy_data_content(data);
    free(data);
}