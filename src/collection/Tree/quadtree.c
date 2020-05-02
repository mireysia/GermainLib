#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/tree/quadtree.h"

QuadTree quadtree_new(void)
{
    quadTree* root = NULL;

    root = (quadTree*)malloc(sizeof(quadTree));

    if( root != NULL )
    {
        root->numberNode = 0;
        root->root = NULL;
    }
    return root;
}

void quadtree_free(QuadTree* root)
{
    if( *root != NULL )
    {
        free(*root);
        *root = NULL;
    }
}

quadTree_node* quadtree_node_new(void)
{
    quadTree_node *node = NULL;

    node = (quadTree_node*)malloc(sizeof(quadTree_node));

    if( node != NULL )
    {
        node->item = NULL;
        node->boundary = NULL;
        node->tabNode[NO] = node->tabNode[NE] = node->tabNode[SO] = node->tabNode[SE] = NULL;
    }
    return node;
}

void quadtree_node_free(quadTree_node **node)
{
    if( *node != NULL )
    {
        (*node)->item = NULL;

        for (unsigned int i = 0; i < QUADTREE_NODE; i++)
            (*node)->tabNode[i] = NULL;
        
        free(*node);
        *node = NULL;
    }
}

bool quadtree_isLeaf(quadTree_node* node)
{
    if( node->tabNode[NO] == NULL && node->tabNode[NE] == NULL && node->tabNode[SE] == NULL && node->tabNode[SO] == NULL )
        return true;
    return false;
}

void quadtree_freeTree(quadTree_node **node, void (*freeItem_function)(void **item))
{
    quadTree_node *_node = *node;
    if( _node != NULL )
    {
        for( unsigned int i = 0 ; i < QUADTREE_NODE ; i++)
            quadtree_freeTree(&(_node->tabNode[i]), freeItem_function);

        if( _node->item != NULL )
            freeItem_function(&(_node->item));

        boundary_t_free(&(_node->boundary));

        free(_node);
        _node = NULL;
    }
    *node = _node;
}