#ifndef __HASH_SET_LIST_H__
#define __HASH_SET_LIST_H__

#include <stdbool.h>

#include "doubleLinkedList.h"
#include "../tree/binaryTree.h"

typedef struct _HAS_SET_LIST hashSetList;
typedef struct _HAS_SET_LIST_FUNCTION hashSetList_function;

typedef hashSetList* HashSetList;

typedef bool (*ptr_function_compare)(void* item1, void* item2);

struct  _HAS_SET_LIST_FUNCTION
{
    ptr_function_compare compare;
    ptr_function_compare equals;
};

struct _HAS_SET_LIST
{
    binaryTree *tree;
    hashSetList_function *function;
    list_ll *list;
};

HashSetList hashSetList_new(void);
void hashSetList_free(HashSetList *hashSetList);

hashSetList_function* hashSetList_function_new( ptr_function_compare *compare, ptr_function_compare *equals);
void hashSetList_function_free(hashSetList_function **function);

#endif