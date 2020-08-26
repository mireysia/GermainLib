#include <stdlib.h>

#include "germainLib/collection/utils/gSimpleLinkNode.h"

gSimpleLinkNode* gSimpleNodeLink_new(void)
{
    gSimpleLinkNode *new  = NULL;

    new  = (gSimpleLinkNode*)malloc(sizeof(gSimpleLinkNode));

    if( new != NULL )
    {
        new->e = NULL;
        new->next = NULL;
    }

    return new; 
}

void gSimpleNodeLink_free( gSimpleLinkNode **node)
{
    if( *node != NULL )
    {
        (*node)->e = NULL;
        (*node)->next = NULL;

        free(*node);
        *node = NULL;
    }
}

void gSimpleNodeLink_headInsert( gSimpleLinkNode **head, gSimpleLinkNode *insert)
{
    insert->next = *head;
    *head = insert;
}

void gSimpleNodeLink_headRemove( gSimpleLinkNode **head, gSimpleLinkNode **remove)
{
    *remove = *head;
    *head = (*head)->next;
}

void gSimpleNodeLink_insert( gSimpleLinkNode *node, gSimpleLinkNode *insert)
{
    insert->next = node->next;
    node->next = insert;
}

void gSimpleNodeLink_remove( gSimpleLinkNode *before, gSimpleLinkNode **remove)
{
    (*remove) = before->next;
    before->next = (*remove)->next;
}