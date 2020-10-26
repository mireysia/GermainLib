#ifndef __G_QUADTREE_H__
#define __G_QUADTREE_H__

#include <stdbool.h>
#include <stdlib.h>

#include "../utils/gElement.h"

#define QTREE_NUMBER_NODE 4

typedef struct _QUADTREE gQTree;
typedef struct _QUADTREE_NODE gQTree_node;
typedef enum gQTree_position_t { NO = 0, NE, SE, SO} gQTree_position_t;

struct _QUADTREE
{
    size_t numberNode;
    gQTree_node *root;
};

struct _QUADTREE_NODE
{
    gElement_t e;

    gQTree_node *node[QTREE_NUMBER_NODE];
};

/**
 * @brief 
 * 
 * @return gQTree* 
 */
gQTree* gQTree_new(void);

/**
 * @brief 
 * 
 * @param tree 
 */
void gQTree_free( gQTree **tree);

/**
 * @brief 
 * 
 * @return gQTree_node* 
 */
gQTree_node* qQTree_newNode(void);

/**
 * @brief 
 * 
 * @param node 
 */
void qQTree_freeNode( gQTree_node **node);

/**
 * @brief 
 * 
 * @param node 
 * @return true 
 * @return false 
 */
bool gQTree_isLeaf( const gQTree_node *node);

/**
 * @brief 
 * 
 * @param tree 
 * @param delete 
 */
void gQTree_delete( gQTree *tree, void (*free)( gElement_t *e));

#endif