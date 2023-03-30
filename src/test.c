#include <stdio.h>
#include <string.h>
#include "cgraph/list/list.h"

void create_list_test(){
    printf("create_list_test: \n");
    list_t* list = create_list();
    if (list == NULL) printf("Out of memory");
    else {

        printf("\t[list->length == 0] ");
        if (list->length == 0) printf("OK\n");
        else printf("NOT OK\n");
        
        printf("\t[list->start == NULL] ");
        if (list->start == NULL) printf("OK\n");
        else printf("NOT OK\n");

        printf("\t[list->end == NULL] ");
        if (list->end == NULL) printf("OK\n");
        else printf("NOT OK\n");

        destroy_list(list);
    }
}

void create_list_and_add_test(){
    printf("create_list_and_add_test: \n");
    list_t* list = create_list();
    if (list == NULL) printf("Out of memory");
    else {
        char character = 'A';
        if(add_to_list(list, "char", 1, &character)){
            printf("Out of memory");
            return;
        }

        printf("\t[list->length == 1] ");
        if (list->length == 1) printf("OK\n");
        else printf("NOT OK\n");
        
        printf("\t[list->start != NULL] ");
        if (list->start != NULL) printf("OK\n");
        else printf("NOT OK\n");

        printf("\t[list->end != NULL] ");
        if (list->end != NULL) printf("OK\n");
        else printf("NOT OK\n");

        printf("\t[list->end == list->start] ");
        if (list->end == list->start) printf("OK\n");
        else printf("NOT OK\n");

        destroy_list(list);
    }
}

void create_list_and_add_many_test(){
    printf("create_list_and_add_many_test: \n");
    list_t* list = create_list();
    if (list == NULL) printf("Out of memory");
    else {
        char character[11] = "ABCDEFGHIJ\0";
        const size_t size = strlen(character);
        for (size_t i = 0; i < size; i++)
        {
            if(add_to_list(list, "char", 1, &character[i])){
                destroy_list(list);
                printf("Out of memory");
                return;
            }
        }

        printf("\t[list->length == %d] ", (int)size);
        if (list->length == size) printf("OK\n");
        else printf("NOT OK\n");
        
        printf("\t[list->start != NULL] ");
        if (list->start != NULL) printf("OK\n");
        else printf("NOT OK\n");

        printf("\t[list->end != NULL] ");
        if (list->end != NULL) printf("OK\n");
        else printf("NOT OK\n");

        printf("\t[list->end == list->start] ");
        if (list->end != list->start) printf("OK\n");
        else printf("NOT OK\n");

        destroy_list(list);
    }
}

int main()
{
    create_list_test();
    create_list_and_add_test();
    create_list_and_add_many_test();
    return 0;
}
