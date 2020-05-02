#include <stdlib.h>
#include <stdio.h>

#include "germainLib/type/integer/integer.h"

void integer_free(int **integer)
{
    if( *integer != NULL )
    {
        free(*integer);
        *integer = NULL;
    }
}

void integer_vt_free(void **integer)
{
    if( *integer != NULL )
    {
        free(*integer);
        *integer = NULL;
    }
}

void integer_display(void *intger)
{
    printf("%d\n", *((int*)(intger)));
}

bool integer_vt_compare(void *integer_1, void *integer_2)
{
    if( *((int*)(integer_1)) == *((int*)(integer_2)) )
        return true;
    return false;
}

bool integer_vt_different(void *integer_1, void *integer_2)
{
    if( *((int*)(integer_1)) != *((int*)(integer_2)) )
        return true;
    return false;
}

void* integer_duplicateInt(void *integer)
{
    int *entier = (int*)malloc(sizeof(int));
    *entier = *((int*)(integer));
    return entier;
}

int* integer_arrays_static_oneDim(const size_t tabSize)
{
    return (int*)calloc(tabSize, sizeof(int));
}

unsigned int integer_arrays_numberOfDifferentInteger(int *intgerTab, const size_t tabSize)
{
    List_l list = list_l_new();

    for( size_t i = 0 ; i < tabSize ; i ++ )
        if( !list_l_contain( list, &intgerTab[i], integer_vt_compare) )
            list_l_duplicateData_add(list, &intgerTab[i], integer_duplicateInt, integer_vt_compare);

    unsigned int data = list_l_size(list);

    list_l_clear( list, integer_vt_free);
    list_l_free(&list);
    return data;
}

List_l integer_arraysToHashSetList(int *intgerTab, const size_t tabSize)
{
    List_l list = list_l_new();

    for( size_t i = 0 ; i < tabSize ; i ++ )
    {
       if( !list_l_contain( list, &intgerTab[i], integer_vt_compare) )
       {
           list_l_duplicateData_add(list, &intgerTab[i], integer_duplicateInt, integer_vt_compare); 
       }            
    }
    return list;
}