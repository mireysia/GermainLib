#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/tree/mAryTreeStatic.h"

aryTree_s_node* aryTree_s_node_new(const int numberNode)
{
    aryTree_s_node *node = NULL;

    node = (aryTree_s*)malloc(sizeof(aryTree_s));

    if( node != NULL )
    {
        node->item = NULL;
        node->numberNode = numberNode;

        node->tabNode = (aryTree_s_node*)malloc(sizeof(aryTree_s_node) * node->numberNode);
    }
    return node;
}
