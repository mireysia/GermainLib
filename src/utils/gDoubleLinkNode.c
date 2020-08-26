#include <stdlib.h>

#include "germainLib/collection/utils/gDoubleLinkNode.h"


gDoubleLinkNode* gDoubleLinkNode_new(void)
{
    gDoubleLinkNode *new = (gDoubleLinkNode*)malloc(sizeof(gDoubleLinkNode));

    if( new != NULL )
    {
        new->e = NULL;
        new->next = NULL;
        new->prev = NULL;
    }
    return new;
}

void gDoubleLinkNode_free( gDoubleLinkNode **node)
{
    if( *node != NULL )
    {
        (*node)->e = NULL;
        (*node)->next = NULL;
        (*node)->prev = NULL;

        free(*node);
        *node = NULL;
    }
}

void gDoubleLinkNode_headInsert( gDoubleLinkNode **head, gDoubleLinkNode *insert)
{
    insert->next = *head;

    if( (*head) != NULL)
        (*head)->prev = insert;

    *head = insert;
}

void gDoubleLinkNode_headRemove( gDoubleLinkNode **head, gDoubleLinkNode **remove)
{
    (*remove) = (*head);
    (*head) = (*head)->next;
    
    if( (*head) != NULL )
        (*head)->prev = NULL;
}

void gDoubleLinkNode_insert( gDoubleLinkNode *node, gDoubleLinkNode *insert)
{
    gDoubleLinkNode *_node = node->next;

    insert->next = node->next;
    insert->prev = node;
    node->next = insert;

    if( insert->next != NULL)
        insert->next->prev = insert;
}

void gDoubleLinkNode_remove( gDoubleLinkNode *node, gDoubleLinkNode **remove)
{
    gDoubleLinkNode *after = node->next;
    gDoubleLinkNode *before = node->prev;

    (*remove) = node;
    before->next = after;

    if( after != NULL )
        after->prev = before;
}

void gDoubleLinkNode_remove_simplify( gDoubleLinkNode *remove)
{
    gDoubleLinkNode *after = NULL;
    gDoubleLinkNode *before = NULL;

    if( remove->next != NULL )
        after = remove->next;

    if( remove->prev != NULL )
        before = remove->prev;

    if( before != NULL )
        before->next = after;
    
    if( after != NULL )
        after->prev = before;
}