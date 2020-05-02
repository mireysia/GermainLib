/**
 * @author ANTUNES Rémi
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "germainLib/collection/list/node_simplelink.h"
#include "germainLib/collection/list/simpleLinkedList.h"

List_l list_l_new(void)
{
    list_l *list = NULL;

    list = (list_l*)malloc(sizeof(list_l));

    if( list != NULL )
    {
        list->head = NULL;
        list->end = NULL;
        list->it = NULL;
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
    if( list->head == NULL || list->nodeNumber == 0 )
        return true;
    return false;
}

unsigned int list_l_size(List_l list)
{
    return list->nodeNumber;
}

node_oneLink* list_l_pSearchIndexe(node_oneLink *head, const int indexe)
{
    unsigned int list_indexe = -1;
    node_oneLink *node = head;
    node_oneLink *before = NULL;

    while( node != NULL && list_indexe != indexe)
    {
        before = node;
        node = node->next;
        list_indexe++;
    }
    return before;
}

node_oneLink* list_l_pSearchIndexeAdd(node_oneLink *head, const int indexe)
{
    unsigned int list_indexe = 0;
    node_oneLink *node = head;
    node_oneLink *before = NULL;

    while( node != NULL && list_indexe != indexe)
    {
        before = node;
        node = node->next;
        list_indexe++;
    }
    return before;
}

node_oneLink *list_l_searchNodeBefor(node_oneLink *head, void *item, bool (*find_function)(void *item, void *itemNode))
{
    node_oneLink *node = head;
    node_oneLink *before = NULL;

    while( node != NULL && !find_function( item, node->item) )
    {
        before = node;
        node = node->next;
    }
    return before;
}

node_oneLink* list_l_pRemoveFirst(List_l list)
{
    if( list->head == NULL )
        return NULL;

    node_oneLink *node = NULL;

    nodeSimpleLink_headRemove(&(list->head), &node);
    (list->nodeNumber)--;
    
    if( list->head == NULL )
        list->end = NULL;

    return node;
}

node_oneLink* list_l_pRemoveLast(List_l list)
{
    if( list->head == NULL )
        return NULL;

    node_oneLink *before = list_l_pSearchIndexe(list->head, list->nodeNumber - 2);
    node_oneLink *node = NULL;

    nodeSimpleLink_remove(before, &node);
    (list->nodeNumber)--;
    list->end = before;

    return node;
}

int list_l_addFirst(List_l list, void *item)
{
    if(item == NULL )
        return LIST_ERROR;

    node_oneLink *node = nodeSimpleLink_alloc();

    node->item = item;

    if( list->head == NULL && list->nodeNumber == 0)
        list->end = node;

    nodeSimpleLink_headInsert(&(list->head), node);
    (list->nodeNumber)++;
    
    return LIST_SUCCESS;
}

int list_l_addLast(List_l list, void *item)
{
    if(item == NULL )
        return LIST_ERROR;

    node_oneLink *node = nodeSimpleLink_alloc();
    
    node->item = item;

    if( list->head == NULL && list->nodeNumber == 0 )
        nodeSimpleLink_headInsert(&(list->head), node);
    else
        nodeSimpleLink_insert( list->end, node);

    list->end = node;
    (list->nodeNumber)++;

    return LIST_SUCCESS;   
}

int list_l_addIndexe(List_l list, void *item, const unsigned int index)
{
    if( index > list->nodeNumber )
        return LIST_ERROR;

    if( index == 0 )
        list_l_addFirst( list, item);
    else
    {
        node_oneLink *insert = nodeSimpleLink_alloc();
        node_oneLink *place = list_l_pSearchIndexeAdd( list->head, index);
        insert->item = item;

        nodeSimpleLink_insert( place, insert);

        (list->nodeNumber)++;

        if( list->end->next != NULL)
            list->end = list->end->next;
    }    
    return LIST_SUCCESS; 
}

int list_l_add(List_l list, void *item, bool (*compare_function)(void* item, void* itemNode))
{
    if(item == NULL )
        return LIST_ERROR;

    node_oneLink *insert = nodeSimpleLink_alloc();
    node_oneLink *before = list_l_searchNodeBefor( list->head, item, compare_function);
    
    insert->item = item;

    if( before == NULL )
        list_l_addFirst( list, item);
    else
    {
        nodeSimpleLink_insert( before, insert);
        if( list->end->next != NULL)
            list->end = list->end->next;
        (list->nodeNumber)++;
    }
    return LIST_SUCCESS;
}

int list_l_duplicateData_add(List_l list, void *item, void* (duplicate_function)(void* data) ,bool (*compare_function)(void* item, void* itemNode))
{
    void *newItem = duplicate_function(item);
    return list_l_add(list, newItem, compare_function);
}

void* list_l_get(const List_l list, const unsigned int index)
{
    if( index < 0 || index > list->nodeNumber )
        return NULL;

    node_oneLink *node = NULL;

    node = (node_oneLink*)list_l_pSearchIndexe(list->head, index);

    if( node != NULL )
        return node->item;
    else
        return NULL;
}

void* list_l_getFirst(const List_l list)
{
    if( list->head != NULL )
        return list->head->item;
    return NULL;
}

void* list_l_getLast(const List_l list)
{
    if( list->end != NULL )
        return list->end->item;
    return NULL;
}

void* list_l_getElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2))
{  
    node_oneLink *node = list->head;
    void *itemFind = NULL;
    unsigned int list_indexe = 0;

    while( node != NULL && !find_function(node->item, item) )
    {
        list_indexe++;
        node = node->next;
    }

    return node->item;
}

int list_l_indexOf(List_l list, void *item, bool (*find_function)(void *item1, void *item2))
{
    node_oneLink *node = list->head;
    bool verificationOk = false;
    unsigned int indexe = 0;

    while( node != NULL && !(find_function( item, node->item)) )
    {
        indexe++;
        node = node->next;
    }

    if( indexe >= list->nodeNumber)
        return -1;
    return indexe;
}

int list_l_lastIndexOf(List_l list, void *item, bool (*find_function)(void *item1, void *item2))
{
    node_oneLink *node = list->head;
    bool verificationOk = find_function( item, node->item);
    int index = -1;
    int lastIndex = -1;

    while( node != NULL )
    {
        index++;
        if(find_function( item, node->item))
            lastIndex = index;      
        node = node->next;
    }
    return lastIndex;
}

void* list_l_pollFirst(List_l list)
{
    node_oneLink *node = list_l_pRemoveFirst(list);
    void *item = NULL;

    if( node != NULL )
    {
        item = node->item;
        nodeSimpleLink_free(&node);
    }

    return item;
}

void* list_l_pollLast(List_l list)
{
    node_oneLink *node = list_l_pRemoveLast(list);
    void *item = NULL;

    if( node != NULL )
    {
        item = node->item;
        nodeSimpleLink_free(&node);
    }
    return item;
}

void* list_l_pollElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2))
{  
    node_oneLink *node = list->head;
    node_oneLink *befor = NULL;
    void *itemFind = NULL;
    unsigned int list_indexe = 0;

    while( node != NULL && !find_function(node->item, item) )
    {
        list_indexe++;
        befor = node;
        node = node->next;
    }

    if( list_indexe < list->nodeNumber )
    {
        if( befor == NULL )
            itemFind = list_l_pollFirst(list);
        else
        {
            node = NULL;
            nodeSimpleLink_remove(befor, &node);
            (list->nodeNumber)--;
            itemFind = node->item;

            if( befor->next == NULL)
                list->end = befor;

            nodeSimpleLink_free(&node);      
        }
    }
    return itemFind;
}

bool list_l_contain(List_l list, void *item, bool (*contain_funcion)(void *item1, void *item2))
{
    bool contain = false;
    node_oneLink *node = list->head;;

    while( node != NULL && !contain )
    {
        contain =contain_funcion(item, node->item);
        node = node->next;
    }
    return contain;
}

int list_l_removeFirst(List_l list, void (*free_function)(void **item))
{
    node_oneLink *node = list_l_pRemoveFirst(list);

    if( node == NULL )
        return LIST_ERROR;

    free_function(&node->item);
    nodeSimpleLink_free(&node);

    return LIST_SUCCESS;
}

int list_l_removeLast(List_l list, void (*free_function)(void **item))
{
    node_oneLink *node = list_l_pRemoveLast(list);

    if( node == NULL )
        return LIST_ERROR;

    free_function(&node->item);
    nodeSimpleLink_free(&node);

    return LIST_SUCCESS;
}

int list_l_removeElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2), void (*free_function)(void **item))
{
    node_oneLink *node = list->head;
    node_oneLink *befor = NULL;
    void *itemFind = NULL;
    unsigned int list_indexe = 0;

    while( node != NULL && !find_function(node->item, item) )
    {
        list_indexe++;
        befor = node;
        node = node->next;
    }

    if( list_indexe < list->nodeNumber )
    {
        if( befor == NULL )
            list_l_removeFirst(list, free_function);
        else
        {
            node = NULL;

            nodeSimpleLink_remove(befor, &node);
            (list->nodeNumber)--;
            free_function(&(node->item));;
            if( befor->next == NULL)
                list->end = befor;
            nodeSimpleLink_free(&node);      
        }
    }
    else
        return LIST_NULL_OBJECT;
    
    return LIST_SUCCESS;
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

void list_l_clear(List_l list, void (*free_function)(void **item))
{
    node_oneLink *node = list->head;
    node_oneLink *tmp = NULL;
    while (node != NULL )
    {
        tmp = node;
        node = node->next;
        free_function(&tmp->item);
        nodeSimpleLink_free(&tmp);
    }
    list->head = list->end = NULL;   
}

void list_l_clearAllNode(List_l list)
{
    node_oneLink *node = list->head;
    node_oneLink *tmp = NULL;
    while (node != NULL )
    {
        tmp = node;
        tmp->item = NULL;
        node = node->next;
        nodeSimpleLink_free(&tmp);
    }
    list->head = list->end = NULL;   
}

void list_l_iterator_new(List_l list)
{
    iterator_l *it = (iterator_l*)malloc(sizeof(iterator_l));

    if( it != NULL )
    {
        it->index = 0;
        it->iterator = list->head;
    }
    list->it = it;
}

bool list_l_iterator_next(List_l list)
{
    if( list->it->iterator != NULL )
    {
        list->it->iterator = list->it->iterator->next;
        list->it->index++;
        return true;
    }
    return false;     
} 

bool list_l_iterator(List_l list)
{
    if( list->it->iterator == NULL )
        return true;
    return false;
}

void *list_l_iterator_get(List_l list)
{
    return list->it->iterator->item;
}

int list_l_iterator_index(List_l list)
{
    return list->it->index;
}

void list_it_iterator_free(List_l list)
{
    if( list->it != NULL )
    {
        list->it->iterator = NULL;
        free(list->it);
        list->it = NULL;
    }
}