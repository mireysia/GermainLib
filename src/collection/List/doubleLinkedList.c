/**
 * @author ANTUNES Rémi
 */
#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/list/doubleLinkedList.h"

List_ll list_ll_new(void)
{
    list_ll *list = NULL;

    list = (list_ll*)malloc(sizeof(list_ll));

    if( list != NULL )
    {
        list->head = NULL;
        list->end = NULL;
        list->it = NULL;
        list->nodeNumber = 0;
    }
    return list;
} 

void list_ll_free(List_ll *list)
{
    if( *list != NULL )
    {
        (*list)->head = NULL;
        (*list)->nodeNumber = 0;

        free(*list);
        *list = NULL;
    }
}

bool list_ll_isEmpty(List_ll list)
{
    if( list->head == NULL && list->nodeNumber == 0 )
        return true;
    return false;
}

unsigned int list_ll_size(List_ll list)
{
    return list->nodeNumber;
}

node_doubleLink* list_ll_pSearchIndexe(node_doubleLink *head, const int indexe)
{
    unsigned int list_indexe = 0;
    node_doubleLink *node = head;

    while( list_indexe != indexe)
    {
        node = node->next;
        list_indexe++;
    }
    return node->prev;
}

node_doubleLink *list_ll_searchNodeBefor(node_doubleLink *head, void *item, bool (*find_function)(void *item, void *itemNode))
{
    node_doubleLink *node = head;
    node_doubleLink *before = NULL;
    bool  verification = false;

    while( node != NULL && !find_function( item, node->item) )
    {      
        before = node;
        node = node->next;
    }
    return before;
}

node_doubleLink* list_ll_pRemoveFirst(List_ll list)
{
    if( list->head == NULL )
        return NULL;

    node_doubleLink *node = NULL;

    nodeDoubleLink_headRemove(&(list->head), &node);
    (list->nodeNumber)--;
    
    if( list->head == NULL )
        list->end = NULL;

    return node;
}

node_doubleLink* list_ll_pRemoveLast(List_ll list)
{
    if( list->head == NULL )
        return NULL;

    node_doubleLink *node = NULL;

    nodeDoubleLink_remove(list->end, &node);
    (list->nodeNumber)--;
    list->end = node->prev;

    return node;
}

int list_ll_addFirst(List_ll list, void *item)
{
    if(item == NULL )
        return LIST_ERROR;

    node_doubleLink *node = nodeDoubleLink_alloc();

    node->item = item;

    if( list->head == NULL)
        list->end = node;

    nodeDoubleLink_headInsert(&(list->head), node);
    (list->nodeNumber)++;
    
    return LIST_SUCCESS;
}

int list_ll_addLast(List_ll list, void *item)
{
    if(item == NULL )
        return LIST_ERROR;

    node_doubleLink *node = nodeDoubleLink_alloc();

    node->item = item;

    if( list->head == NULL )
        nodeDoubleLink_headInsert(&(list->head), node);
    else
        nodeDoubleLink_insert( list->end, node);
    
    list->end = node;
    (list->nodeNumber)++;

    return LIST_SUCCESS;   
}

int list_ll_addIndexe(List_ll list, void *item, const unsigned int index)
{
    if( index < 0 || index > list->nodeNumber )
        return LIST_ERROR;

    if( index == 0 )
        list_ll_addFirst( list, item);
    else if ( index == list->nodeNumber)
        list_ll_addLast( list, item);
    else
    {       
        node_doubleLink *place = list_ll_pSearchIndexe( list->head, index);
        node_doubleLink *insert = nodeDoubleLink_alloc();
        insert->item = item;

        nodeDoubleLink_insert( place, insert);
        (list->nodeNumber)++;

        if( list->end->next != NULL)
            list->end = insert;
    }    
    return LIST_SUCCESS; 
}

int list_ll_add(List_ll list, void *item, bool (*compare_function)(void* item, void* itemNode))
{
    if(item == NULL )
        return LIST_ERROR;

    node_doubleLink *before = list_ll_searchNodeBefor( list->head, item, compare_function);
    node_doubleLink *insert = nodeDoubleLink_alloc();
    insert->item = item;

    if( before == NULL )
        list_ll_addFirst( list, item);
    else
    {
        nodeDoubleLink_insert( before, insert);
        if( list->end->next != NULL)
            list->end = insert;
        (list->nodeNumber)++;
    }
    return LIST_SUCCESS;
}

void* list_ll_get(const List_ll list, const unsigned int index)
{
    if( index < 0 || index > list->nodeNumber )
        return NULL;

    if( index == 0 )
        return list_ll_getFirst(list);
    else if( index == list->nodeNumber - 1 )
        return list_ll_getLast(list);
    else
    {
        node_doubleLink *node = NULL;
        node = (node_doubleLink*)list_ll_pSearchIndexe(list->head, index);
        return node->next->item;
    }
    return NULL;
}

void* list_ll_getFirst(const List_ll list)
{
    if( list->head != NULL )
        return list->head->item;
    return NULL;
}

void* list_ll_getLast(const List_ll list)
{
    if( list->end != NULL )
        return list->end->item;
    return NULL;
}

void* list_ll_getElement(List_ll list, void *item, bool (*find_function)(void *item1, void *item2))
{  
    node_doubleLink *node = list->head;

    while( node != NULL && !find_function(node->item, item) )
    {
        node = node->next;
    }

    return node->item;
}

int list_ll_indexOf(List_ll list, void *item, bool (*find_function)(void *item1, void *item2))
{
    node_doubleLink *node = list->head;
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

int list_ll_lastIndexOf(List_ll list, void *item, bool (*find_function)(void *item1, void *item2))
{
    node_doubleLink *node = list->head;
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

void* list_ll_pollFirst(List_ll list)
{
    node_doubleLink *node = list_ll_pRemoveFirst(list);
    void *item = NULL;

    if( node != NULL )
    {
        item = node->item;
        nodeDoubleLink_free(&node);
    }
    return item;
}

void* list_ll_pollLast(List_ll list)
{
    node_doubleLink *node = list_ll_pRemoveLast(list);
    void *item = NULL;

    if( node != NULL )
    {
        item = node->item;
        nodeDoubleLink_free(&node);
    }
    return item;
}

void* list_ll_pollElement(List_ll list, void *item, bool (*find_function)(void *item1, void *item2))
{  
    node_doubleLink *node = list->head;
    node_doubleLink *befor = NULL;
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
            itemFind = list_ll_pollFirst(list);
        else
        {
            node = NULL;
            nodeDoubleLink_remove(befor, &node);
            (list->nodeNumber)--;
            itemFind = node->item;

            if( befor->next == NULL)
                list->end = befor;

            nodeDoubleLink_free(&node);      
        }
    }
    return itemFind;
}

bool list_ll_contain(List_ll list, void *item, bool (*contain_funcion)(void *item1, void *item2))
{
    bool contain = false;
    node_doubleLink *node = list->head;;

    while( node != NULL && !contain )
    {
        contain =contain_funcion(item, node->item);
        node = node->next;
    }
    return contain;
}

int list_ll_removeFirst(List_ll list, void (*free_function)(void **item))
{
    node_doubleLink *node = list_ll_pRemoveFirst(list);

    if( node == NULL )
        return LIST_ERROR;

    free_function(&node->item);
    nodeDoubleLink_free(&node);

    return LIST_SUCCESS;
}

int list_ll_removeLast(List_ll list, void (*free_function)(void **item))
{
    node_doubleLink *node = list_ll_pRemoveLast(list);

    if( node == NULL )
        return LIST_ERROR;

    free_function(&node->item);
    nodeDoubleLink_free(&node);

    return LIST_SUCCESS;
}

int list_ll_removeElement(List_ll list, void *item, bool (*find_function)(void *item1, void *item2), void (*free_function)(void **item))
{
    node_doubleLink *node = list->head;
    void *itemFind = NULL;
    unsigned int list_indexe = 0;

    while( node != NULL && !find_function(node->item, item) )
    {
        list_indexe++;
        node = node->next;
    }

    if( list_indexe < list->nodeNumber )
    {
        if( node->prev == NULL )
            list_ll_removeFirst(list, free_function);
        else
        {
            node_doubleLink *remove = NULL;

            nodeDoubleLink_remove(node, &remove);
            (list->nodeNumber)--;
            if( node->next == NULL)
                list->end = node->prev;
            free_function(&(remove->item));;            
            nodeDoubleLink_free(&remove);      
        }
    }
    else
        return LIST_NULL_OBJECT;
    
    return LIST_SUCCESS;
}

void list_ll_display(List_ll list, void (*display_function)(void *item))
{
    node_doubleLink *node = NULL;

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

void list_ll_clear(List_ll list, void (*free_function)(void **item))
{
    node_doubleLink *node = list->head;
    node_doubleLink *tmp = NULL;

    while (node != NULL )
    {
        tmp = node;
        node = node->next;
        free_function(&tmp->item);
        nodeDoubleLink_free(&tmp);
    }

    list->head = list->end = NULL;   
}

void list_ll_iterator_new(List_ll list)
{
    iterator_ll *it = (iterator_ll*)malloc(sizeof(iterator_ll));

    if( it != NULL )
    {
        it->index = 0;
        it->iterator = list->head;
    }
    list->it = it;
}

void list_ll_iterator_new_end(List_ll list)
{
    iterator_ll *it = (iterator_ll*)malloc(sizeof(iterator_ll));

    if( it != NULL )
    {
        it->index = 0;
        it->iterator = list->end;
    }
    list->it = it;
}

bool list_ll_iterator_next(List_ll list)
{
    if( list->it->iterator != NULL )
    {
        list->it->iterator = list->it->iterator->next;
        list->it->index++;
        return true;
    }
    return false;       
} 

bool list_ll_iterator_prev(List_ll list)
{
    if( list->it->iterator != NULL )
    {
        list->it->iterator = list->it->iterator->prev;
        list->it->index++;
        return true;
    }
    return false;       
} 

bool list_ll_iterator(List_ll list)
{
    if( list->it->iterator == NULL )
        return true;
    return false;
}

int list_ll_iterator_jump(List_ll list)
{
    if( list->it == NULL )
        return LIST_ERROR;

    if( list_ll_iterator_next(list) )
        return LIST_SUCCESS;

    return LIST_ERROR;
}

void *list_ll_iterator_get(List_ll list)
{
    return list->it->iterator->item;
}

void *list_ll_iterator_getNext(List_ll list)
{
    if( list->it->iterator->next != NULL )
        return list->it->iterator->next->item;
    return NULL;
}

int list_ll_iterator_index(List_ll list)
{
    return list->it->index;
}

void list_ll_it_iterator_free(List_ll list)
{
    if( list->it != NULL )
    {
        list->it->iterator = NULL;
        
        free(list->it);
        list->it = NULL;
    }
}