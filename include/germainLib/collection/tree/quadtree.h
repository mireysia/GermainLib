#ifndef __QUADTREE_H__
#define __QUADTREE_H__

#include <stdbool.h>

#include "germainLib/geometry.h"
#include "germainLib/color.h"

#define QUADTREE_NODE 4

typedef struct _QUADTREE quadTree;
typedef struct _QUADTREE_NODE quadTree_node;

typedef quadTree* QuadTree;
typedef int tag_node;

typedef enum qtree_position { NO, NE, SE, SO} qtree_position;

struct _QUADTREE
{
    size_t numberNode;
    quadTree_node *root;
};

struct _QUADTREE_NODE
{
    void *item;
    
    boundary_t *boundary;

    quadTree_node *tabNode[QUADTREE_NODE];
};

QuadTree quadtree_new(void);

void quadtree_free(QuadTree* root);

quadTree_node* quadtree_node_new(void);

void quadtree_node_free(quadTree_node **node);

bool quadtree_isLeaf(quadTree_node* node);

void quadtree_freeTree(quadTree_node **node, void (*freeItem_function)(void **item));

#endif