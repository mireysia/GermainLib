#ifndef __N_ARRAY_TREE_STATIC_H__
#define __N_ARRAY_TREE_STATIC_H__

typedef struct _M_ARY_TREE_STATIC aryTree_s;
typedef struct _M_ARY_TREE_STATIC_NODE aryTree_s_node;

typedef aryTree_s* AryTree_s;

struct _M_ARY_TREE_STATIC
{
    aryTree_s_node *root;
};

struct _M_ARY_TREE_STATIC_NODE
{
    void *item;
    size_t numberNode;
    aryTree_s_node **tabNode;
};

aryTree_s_node* aryTree_s_node_new(const int numberNode);
aryTree_s_node* aryTree_s_node_newNode(const int numberNode, void *item);

void aryTree_s_node_free(aryTree_s **node);

#endif