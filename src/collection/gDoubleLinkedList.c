#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/gDoubleLinkedList.h"

gList_ll* gListll_new(void)
{
    gList_ll* list = NULL;

    list = (gList_ll*)malloc(sizeof(gList_ll));

    if( list != NULL )
    {
        list->head = NULL;
        list->end = NULL;
        list->size = 0UL;
    }
    return list;
} 

void gListll_free( gList_ll **list)
{
    if( *list != NULL )
    {
        (*list)->head = NULL;
        (*list)->end = NULL;

        free(*list);
        *list = NULL;
    }
}

bool gListll_isEmpty( gList_ll *list)
{
    if( list->head == NULL && list->size == 0UL )
        return true;
    return false;
}

size_t gListll_size( gList_ll *list)
{
    return list->size;
}

gDoubleLinkNode* searchIndex( gDoubleLinkNode *head, const size_t indexe)
{
    size_t list_indexe = 0;
    gDoubleLinkNode *node = head;

    while( list_indexe != indexe)
    {
        node = node->next;
        list_indexe++;
    }
    return node->prev;
}

gDoubleLinkNode* searchNodeBefore( gDoubleLinkNode *head, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2))
{
    gDoubleLinkNode *node = head;
    gDoubleLinkNode *before = NULL;

    while( node != NULL && !find( e, node->e) )
    {      
        before = node;
        node = node->next;
    }
    return before;
}

gDoubleLinkNode* removeFirst( gList_ll *list)
{
    if( list->head == NULL )
        return NULL;

    gDoubleLinkNode *node = NULL;

    gDoubleLinkNode_headRemove(&(list->head), &node);
    (list->size)--;
    
    if( list->head == NULL )
        list->end = NULL;

    return node;
}

gDoubleLinkNode* removeLast( gList_ll *list)
{
    if( list->head == NULL )
        return NULL;

    if( list->size < 2 )
        return removeFirst( list);
    else
    {
        gDoubleLinkNode *node = list->end;

        list->end = node->prev;
        gDoubleLinkNode_remove_simplify( node);
        (list->size)--;

        return node;
    }
}

void gListll_addFirst( gList_ll *list, gElement_t e)
{
    if( e != NULL )
    {
        gDoubleLinkNode *node = gDoubleLinkNode_new();

        node->e = e;

        if( list->head == NULL)
            list->end = node;

        gDoubleLinkNode_headInsert(&(list->head), node);

        (list->size)++;
    }
}

void gListll_addLast( gList_ll *list, gElement_t e)
{
    if( e != NULL )
    {
        gDoubleLinkNode *node = gDoubleLinkNode_new();

        node->e = e;

        if( list->head == NULL )
            gDoubleLinkNode_headInsert( &(list->head), node);
        else
            gDoubleLinkNode_insert( list->end, node);
        
        list->end = node;
        (list->size)++;   
    }  
}

void gListll_addIndexe( gList_ll *list, gElement_t e, const size_t index)
{
    if( index < 0 || index > list->size )
        return;

    if( index == 0 )
        gListll_addFirst( list, e);
    else if ( index == list->size)
        gListll_addLast( list, e);
    else
    {       
        gDoubleLinkNode *place = searchIndex( list->head, index);
        gDoubleLinkNode *insert = gDoubleLinkNode_new();
        insert->e = e;

        gDoubleLinkNode_insert( place, insert);
        (list->size)++;

        if( list->end->next != NULL)
            list->end = insert;
    }    
}

void gListll_add( gList_ll *list, gElement_t e, bool (*compare)( const gElement_t e1, const gElement_t e2))
{
    if( e != NULL )
    {
        gDoubleLinkNode *before = searchNodeBefore( list->head, e, compare);

        if( before == NULL )
            gListll_addFirst( list, e);
        else
        {
            gDoubleLinkNode *insert = gDoubleLinkNode_new();
            insert->e = e;

            gDoubleLinkNode_insert( before, insert);

            if( list->end == before)
                list->end = insert;

            (list->size)++;
        }
    }
}

gElement_t gListll_get( const gList_ll  *list, const size_t index)
{
    if( index < 0 || index > list->size )
        return NULL;

    if( index == 0 )
        return gListll_getFirst(list);
    else if( index == list->size - 1 )
        return gListll_getLast(list);
    else
    {
        gDoubleLinkNode *node = NULL;
        node = (gDoubleLinkNode*)searchIndex(list->head, index);
        return node->next->e;
    }
    return NULL;
}

gElement_t gListll_getFirst( const gList_ll *list)
{
    if( list->head != NULL )
        return list->head->e;
    return NULL;
}

gElement_t gListll_getLast(const gList_ll *list)
{
    if( list->end != NULL )
        return list->end->e;
    return NULL;
}

gElement_t gListll_getElement( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2))
{  
    gDoubleLinkNode *node = list->head;

    while( node != NULL && !find( e, node->e) )
    {
        node = node->next;
    }

    if( node == NULL )
        return NULL;
    else
        return node->e;
}

size_t gListll_indexOf( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2))
{
    gDoubleLinkNode *node = list->head;
    size_t index = 0;

    while( node != NULL && !(find( e, node->e)) )
    {
        index++;
        node = node->next;
    }

    if( index >= list->size)
        return -1;
    return index;
}

size_t gListll_lastIndexOf( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2))
{
    gDoubleLinkNode *node = list->head;
    size_t index = -1;
    size_t lastIndex = -1;

    while( node != NULL )
    {
        index++;
        if( find( e, node->e))
            lastIndex = index;      
        node = node->next;
    }
    return lastIndex;
}

gElement_t gListll_pollFirst( gList_ll *list)
{
    gDoubleLinkNode *node = removeFirst(list);
    gElement_t e = NULL;

    if( node != NULL )
    {
        e = node->e;
        gDoubleLinkNode_free(&node);
    }
    return e;
}

gElement_t gListll_pollLast( gList_ll *list)
{
    gDoubleLinkNode *node = removeLast(list);
    gElement_t e = NULL;

    if( node != NULL )
    {
        e = node->e;
        gDoubleLinkNode_free(&node);
    }
    return e;
}

gElement_t gListll_pollElement( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2))
{  
    gDoubleLinkNode *node = list->head;
    gElement_t item = NULL;
    size_t list_indexe = 0;

    while( node != NULL && !find(node->e, e) )
    {
        list_indexe++;
        node = node->next;
    }

    if( list_indexe < list->size )
    {
        if( list_indexe == 0 )
            item = gListll_pollFirst(list);
        else
        {    
            gDoubleLinkNode_remove_simplify( node);
            (list->size)--;
            item = node->e;

            if( node->next == NULL)
                list->end = node;

            gDoubleLinkNode_free(&node);      
        }
    }
    return item;
}

bool gListll_contain( gList_ll *list, gElement_t e, bool (*contain)( const gElement_t e1, const gElement_t e2))
{
    bool isPresent = false;
    gDoubleLinkNode *node = list->head;;

    while( node != NULL && !isPresent )
    {
        isPresent =contain( e, node->e);
        node = node->next;
    }
    return isPresent;
}

void gListll_removeFirst( gList_ll *list, void (*free)( gElement_t *e))
{
    gDoubleLinkNode *node = removeFirst(list);

    if( node != NULL )
    {
        free(&node->e);
        gDoubleLinkNode_free(&node);
    }
}

void gListll_removeLast( gList_ll *list, void (*free)( gElement_t *e))
{
    gDoubleLinkNode *node = removeLast(list);

    if( node != NULL )
    {
        free(&node->e);
        gDoubleLinkNode_free(&node);   
    }
}

void gListll_removeElement( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2), void (*free)( gElement_t *e))
{
    gDoubleLinkNode *node = list->head;
    size_t index = 0;

    while( node != NULL && !find(node->e, e) )
    {
        index++;
        node = node->next;
    }

    if( index < list->size )
    {
        if( node->prev == NULL )
            gListll_removeFirst(list, free);
        else
        {
            gDoubleLinkNode *remove = NULL;

            gDoubleLinkNode_remove(node, &remove);
            (list->size)--;

            if( node->next == NULL)
                list->end = node->prev;

            free(&(remove->e));        
            gDoubleLinkNode_free(&remove);      
        }
    }
}

void gListll_display( gList_ll *list, void (*display)( const gElement_t e))
{
    gDoubleLinkNode *node = NULL;

    if( list != NULL )
    {
        node = list->head;
        while( node != NULL )
        {
            display(node->e);
            node = node->next;
        }
        printf("\n");
    }
}

void gListll_clear( gList_ll *list, void (*free)( gElement_t *e))
{
    gDoubleLinkNode *node = list->head;
    gDoubleLinkNode *tmp = NULL;

    while (node != NULL )
    {
        tmp = node;
        node = node->next;
        free(&tmp->e);

        gDoubleLinkNode_free(&tmp);
    }

    list->head = list->end = NULL;   
}

void gListll_clearNode( gList_ll *list)
{
    gDoubleLinkNode *node = list->head;
    gDoubleLinkNode *tmp = NULL;

    while (node != NULL )
    {
        tmp = node;
        tmp->e = NULL;
        node = node->next;
        gDoubleLinkNode_free(&tmp);
    }

    list->size = 0;
    list->head = list->end = NULL;   
}