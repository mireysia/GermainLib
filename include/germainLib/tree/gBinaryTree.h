#ifndef __G_BINARY_TREE_H__
#define __G_BINARY_TREE_H__

#include <stdbool.h>

#include "../utils/gElement.h"

typedef struct _BINARY_TREE_NODE gBTree_node;
typedef struct _BINARY_TREE gBTree;

struct _BINARY_TREE
{
    struct gBTree_node *root;
};

struct _BINARY_TREE_NODE
{
    gElement_t e;

    gBTree_node *right;
    gBTree_node *left;
};

/**
 * @brief 
 * 
 * @return gBTree* 
 */
gBTree* gBTree_new(void);

/**
 * @brief 
 * 
 * @return gBTree_node* 
 */
gBTree_node* gBTree_newNode(void);

/**
 * @brief 
 * 
 * @param tree 
 */
void gBTree_free( gBTree **tree);

/**
 * @brief 
 * 
 * @param node 
 */
void gBTree_freeNode( gBTree_node **node);

/**
 * @brief 
 * 
 * @param node 
 * @return true 
 * @return false 
 */
bool gBTree_isLeaf( const gBTree_node *node);

#endif