#ifndef DATA_H
#define DATA_H
#include <stdlib.h>

typedef struct data_s
{
    char* data_type;
    size_t data_size;
    void* data;
} data_t;

static const size_t SIZE_OF_DATA = sizeof(data_t);

data_t* create_data(char* content_type, size_t content_size, void* content);
void destroy_data(data_t* data);
#endif