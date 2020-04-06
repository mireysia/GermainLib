/**
 * @author ANTUNES Rémi
 */
#include <stdio.h>
#include <stdlib.h>

#include "germainLib/node_simplelink.h"

node_oneLink* nodeSimpleLink_alloc(void)
{
    node_oneLink *node = NULL;

    node = (node_oneLink*)malloc(sizeof(node_oneLink));

    if( node != NULL )
    {
        node->item = NULL;
        node->next = NULL;
    }
    return node;
}

void nodeSimpleLink_free(node_oneLink **node)
{
    if( *node != NULL )
    {
        free(*node);
        *node = NULL;
    }
}

void nodeSimpleLink_headInsert(node_oneLink **head, node_oneLink *insert)
{
    insert->next = *head;
    *head = insert;
}

void nodeSimpleLink_headRemove(node_oneLink **head, node_oneLink **remove)
{
    *remove = *head;
    *head = (*head)->next;
}

void nodeSimpleLink_insert(node_oneLink *node, node_oneLink *insert)
{
    insert->next = node->next;
    node->next = insert;
}
// *node -> maillon precedent a celui que nous voulons retirer
void nodeSimpleLink_remove(node_oneLink *precedent, node_oneLink **remove)
{
    (*remove) = precedent->next;
    precedent->next = (*remove)->next;
}

void nodeSimpleLink_swap(node_oneLink *precedent, node_oneLink **remove);