/**
 * @author ANTUNES Rémi
 */
#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/list/node_doublelink.h"

node_doubleLink* nodeDoubleLink_alloc(void)
{
    node_doubleLink *node = NULL;

    node = (node_doubleLink*)malloc(sizeof(node_doubleLink));

    if(node != NULL)
    {
        node->item = NULL;
        node->next = node->prev = NULL;
    }
    return node;
}

void nodeDoubleLink_free(node_doubleLink **node)
{
    if(*node != NULL)
    {
        (*node)->item = NULL;
        (*node)->next = (*node)->prev = NULL;
        free(*node);
        *node = NULL;
    }
}

void nodeDoubleLink_headInsert(node_doubleLink **head, node_doubleLink *insert)
{
    insert->next = *head;

    if( (*head) != NULL)
        (*head)->prev = insert;

    *head = insert;
}

void nodeDoubleLink_headRemove(node_doubleLink **head, node_doubleLink **remove)
{
    (*remove) = (*head);
    (*head) = (*head)->next;
    
    if( (*head) != NULL )
        (*head)->prev = NULL;
}

void nodeDoubleLink_insert(node_doubleLink *node, node_doubleLink *insert)
{
    node_doubleLink *_node = node->next;

    insert->next = _node;
    insert->prev = node;
    node->next = insert;

    if( _node != NULL)
        _node->prev = insert;
}

void nodeDoubleLink_remove(node_doubleLink *node, node_doubleLink **remove)
{
    node_doubleLink *after = node->next;
    node_doubleLink *befor = node->prev;

    befor->next = after;

    if( after != NULL )
        after->prev = befor;

    (*remove) = node;
}