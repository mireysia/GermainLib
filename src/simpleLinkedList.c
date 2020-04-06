/**
 * @author ANTUNES Rémi
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "germainLib/node_simplelink.h"
#include "germainLib/simpleLinkedList.h"

List_l list_l_alloc(void)
{
    list_l *list = NULL;

    list = (list_l*)malloc(sizeof(list_l));

    if( list != NULL )
    {
        list->head = list->end = NULL;
        list->nodeNumber = 0;
    }
    return list;
} 

void list_l_free(List_l *list)
{
    if( *list != NULL )
    {
        (*list)->head = NULL;
        (*list)->nodeNumber = 0;

        free(*list);
        *list = NULL;
    }
}

bool list_l_isEmpty(List_l list)
{
    if( list->head == NULL && list->nodeNumber == 0 )
        return true;
    return false;
}

unsigned int list_l_size(List_l list)
{
    return list->nodeNumber;
}

void list_l_searchIndexe(node_oneLink *head, const int indexe, node_oneLink **nodeSearch)
{
    unsigned int list_indexe = -1;

    while( head != NULL && list_indexe != indexe)
    {
        head = head->next;
        list_indexe++;
    }
    (*nodeSearch) = head;
}

int list_l_addFirst(List_l list, void *item)
{
    if( list == NULL || item == NULL )
        return LIST_ERROR;

    node_oneLink *node = nodeSimpleLink_alloc();

    if( node == NULL )
        return LIST_ERROR;

    node->item = item;

    if( list->head == NULL && list_l_isEmpty(list) && list->end == NULL)
        list->end = node;

    nodeSimpleLink_headInsert(&(list->head), node);
    (list->nodeNumber)++;
    
    return LIST_SUCCESS;
}

int list_l_add(List_l list, void *item)
{
    if( list == NULL || item == NULL )
        return LIST_ERROR;

    node_oneLink *node = nodeSimpleLink_alloc();

    if( node == NULL )
        return LIST_ERROR;
    
    node->item = item;

    if( list->head == NULL && list->end == NULL && list_l_isEmpty(list) )
        nodeSimpleLink_headInsert(&(list->head), node);
    else
        nodeSimpleLink_insert( list->end, node);

    list->end = node;
    (list->nodeNumber)++;

    return LIST_SUCCESS;   
}

void* list_l_get(const List_l list, const unsigned int indexe)
{
    if( list == NULL || (list->head == NULL && list_l_isEmpty(list)) )
        return NULL;

    node_oneLink *node = NULL;

    list_l_searchIndexe(list->head, indexe, &node);

    if( node != NULL )
        return node->item;
    else
        return NULL;
}

unsigned int list_l_indexOf(List_l list, void *item, bool (*find_function)(void *item1, void *item2))
{
    if( item == NULL )
        return -1;

    node_oneLink *node = list->head;
    bool verificationOk = false;
    unsigned int indexe = -1;

    while( node != NULL && !verificationOk )
    {
        indexe++;
        verificationOk = find_function( item, node->item);
        node = node->next;
    }
    return indexe;
}

void* list_l_pollFirst(List_l list)
{
    if( list == NULL || list_l_isEmpty(list) || list->head == NULL )
        return NULL;

    node_oneLink *node = NULL;
    void *item = NULL;

    nodeSimpleLink_headRemove(&(list->head), &node);
    (list->nodeNumber)--;

    if( list->head == NULL )
        list->end = NULL;

    item = node->item;
    nodeSimpleLink_free(&node);
    return item;
}

bool list_l_contain(List_l list, void *item, bool (*contain_funcion)(void *item1, void *item2))
{
    bool contain = false;
    node_oneLink *node = NULL;

    node = list->head;
    while( node != NULL && contain == false )
    {
        contain = contain_funcion(item, node->item);
        node = node->next;
    }
    return contain;
}

void* list_l_findElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2))
{
    bool findElement = false;
    node_oneLink *node = NULL;
    node_oneLink *nodeFind = NULL;

    node = list->head;

    while( node != NULL && findElement == false )
    {
        findElement = find_function(node->item, item);

        if( findElement == true )
            nodeFind = node;
        node = node->next;
    }
    return nodeFind->item;
}

void list_l_display(List_l list, void (*display_function)(void *item))
{
    node_oneLink *node = NULL;

    if( list != NULL )
    {
        node = list->head;
        while( node != NULL )
        {
            display_function(node->item);
            node = node->next;
        }
        printf("\n");
    }
}

void list_l_clear(List_l list)
{
    const unsigned int number_node = (list)->nodeNumber;

    for( unsigned int i = 0 ; i < number_node ; i++ )
        list_l_pollFirst(list);
    
}