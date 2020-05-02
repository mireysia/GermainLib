#ifndef __N_ARRAY_TREE_STATIC_H__
#define __N_ARRAY_TREE_STATIC_H__

#include "../list/doubleLinkedList.h"

typedef struct _M_ARY_TREE_DYNAMIC aryTree_d;
typedef struct _M_ARY_TREE_DYNAMIC_NODE aryTree_d_node;

typedef aryTree_d* AryTree_d;

struct _M_ARY_TREE_DYNAMIC
{
    aryTree_d_node *root;
};

struct _M_ARY_TREE_DYNAMIC_NODE
{
    void *item;
    List_ll *node;
};

#endif