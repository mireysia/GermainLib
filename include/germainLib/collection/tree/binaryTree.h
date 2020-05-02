#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

typedef struct _BINARYTREE_NODE binaryTree_node;
typedef struct _BINARYTREE binaryTree;
typedef binaryTree* BinaryTree;
typedef enum { POST_FIXE, PRE_FIXE, IN_FIXE}displayMode;

struct _BINARYTREE
{
    binaryTree_node *root;
};

struct _BINARYTREE_NODE
{
    void *item;

    binaryTree_node *left;
    binaryTree_node *right;
};

#endif