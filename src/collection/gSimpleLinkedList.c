#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/gSimpleLinkedList.h"

gList_l* gListl_new(void)
{
    gList_l *list = NULL;

    list = (gList_l*)malloc(sizeof(gList_l));

    if( list != NULL )
    {
        list->head = NULL;
        list->end = NULL;
        list->size = 0UL;
    }
    return list;
} 

void gListl_free( gList_l **list)
{
    if( *list != NULL )
    {
        (*list)->head = NULL;

        free(*list);
        *list = NULL;
    }
}

bool gListl_isEmpty( gList_l *list)
{
    if( list->head == NULL || list->size == 0 )
        return true;
    return false;
}

size_t gListl_size( gList_l *list)
{
    return list->size;
}

gSimpleLinkNode* gListl_p_searchIndex( gSimpleLinkNode *head, const size_t index)
{
    unsigned int list_indexe = -1;
    gSimpleLinkNode *node = head;
    gSimpleLinkNode *before = NULL;

    while( node != NULL && list_indexe != index)
    {
        before = node;
        node = node->next;
        list_indexe++;
    }
    return before;
}

gSimpleLinkNode* gListl_p_searchIndexeAdd( gSimpleLinkNode *head, const size_t index)
{
    unsigned int list_indexe = 0;
    gSimpleLinkNode *node = head;
    gSimpleLinkNode *before = NULL;

    while( node != NULL && list_indexe != index)
    {
        before = node;
        node = node->next;
        list_indexe++;
    }
    return before;
}

gSimpleLinkNode* gListl_p_searchNodeBefore( gSimpleLinkNode *head, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2))
{
    gSimpleLinkNode *node = head;
    gSimpleLinkNode *before = NULL;

    while( node != NULL && !find( e, node->e) )
    {
        before = node;
        node = node->next;
    }
    return before;
}

gSimpleLinkNode* gListl_p_removeFirst( gList_l *list)
{
    if( list->head == NULL )
        return NULL;

    gSimpleLinkNode *node = NULL;

    gSimpleNodeLink_headRemove(&(list->head), &node);
    (list->size)--;
    
    if( list->head == NULL )
        list->end = NULL;

    return node;
}

gSimpleLinkNode* gListl_p_removeLast( gList_l *list)
{
    if( list->head == NULL )
        return NULL;

    gSimpleLinkNode *before = gListl_p_searchIndex(list->head, list->size - 2);
    gSimpleLinkNode *node = NULL;

    gSimpleNodeLink_remove(before, &node);
    (list->size)--;
    list->end = before;

    return node;
}

void gListl_addFirst(  gList_l *list, gElement_t e)
{
    if( e != NULL )
    {
        gSimpleLinkNode *node = gSimpleNodeLink_new();

        node->e = e;

        if( list->head == NULL && list->size == 0)
            list->end = node;

        gSimpleNodeLink_headInsert(&(list->head), node);
        (list->size)++;
    }
}

void gListl_addLast( gList_l *list, gElement_t e)
{
    if( e != NULL )
    {
        gSimpleLinkNode *node = gSimpleNodeLink_new();
    
        node->e = e;

        if( list->head == NULL && list->size == 0 )
            gSimpleNodeLink_headInsert(&(list->head), node);
        else
            gSimpleNodeLink_insert( list->end, node);

        list->end = node;
        (list->size)++;
    } 
}

void gListl_addIndexe( gList_l *list, gElement_t e, const size_t index)
{
    if( index < list->size )
    {
        if( index == 0 )
            gListl_addFirst( list, e);
        else
        {
            gSimpleLinkNode *insert = gSimpleNodeLink_new();
            gSimpleLinkNode *place = gListl_p_searchIndexeAdd( list->head, index);
            insert->e = e;

            gSimpleNodeLink_insert( place, insert);

            (list->size)++;

            if( list->end->next != NULL)
                list->end = list->end->next;
        } 
    }
}

void gListl_add( gList_l *list, gElement_t e, bool (*compare)( gElement_t e1, gElement_t e2))
{
    if( e != NULL )
    {
        gSimpleLinkNode *insert = NULL;
        gSimpleLinkNode *before = gListl_p_searchNodeBefore( list->head, e, compare);

        if( before == NULL )
            gListl_addFirst( list, e);
        else
        {
            insert = gSimpleNodeLink_new();
            insert->e = e;

            gSimpleNodeLink_insert( before, insert);

            if( list->end->next != NULL)
                list->end = list->end->next;
            (list->size)++;
        }
    }
}

gElement_t gListl_get( const gList_l *list, const size_t index)
{
    if( index < 0 || index > list->size )
        return NULL;

    gSimpleLinkNode *node = gListl_p_searchIndex(list->head, index);

    if( node != NULL )
        return node->e;
    else
        return NULL;
}

gElement_t gListl_getFirst( const gList_l *list)
{
    if( list->head != NULL )
        return list->head->e;
    return NULL;
}

gElement_t gListl_getLast( const gList_l *list)
{
    if( list->end != NULL )
        return list->end->e;
    return NULL;
}

gElement_t gListl_getElement( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2))
{  
    gSimpleLinkNode *node = list->head;

    while( node != NULL && !find(node->e, e) )
    {
        node = node->next;
    }
    if( node == NULL )
        return NULL;
    else
        return node->e;
}

size_t gListl_indexOf( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2))
{
    gSimpleLinkNode *node = list->head;
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

size_t gListl_lastIndexOf( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2))
{
    gSimpleLinkNode *node = list->head;
    int index = -1;
    int lastIndex = -1;

    while( node != NULL )
    {
        index++;
        if(find( e, node->e))
            lastIndex = index;      
        node = node->next;
    }
    return lastIndex;
}

gElement_t gListl_pollFirst( gList_l *list)
{
    gSimpleLinkNode *node = gListl_p_removeFirst(list);
    gElement_t e = NULL;

    if( node != NULL )
    {
        e = node->e;
        gSimpleNodeLink_free(&node);
    }

    return e;
}

gElement_t gListl_pollLast( gList_l *list)
{
    gSimpleLinkNode *node = gListl_p_removeLast(list);
    gElement_t e = NULL;

    if( node != NULL )
    {
        e = node->e;
        gSimpleNodeLink_free(&node);
    }
    return e;
}

gElement_t gListl_pollElement( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2))
{  
    gSimpleLinkNode *node = list->head;
    gSimpleLinkNode *before = NULL;
    gElement_t item = NULL;
    size_t index = 0;

    while( node != NULL && !find(node->e, e) )
    {
        index++;
        before = node;
        node = node->next;
    }

    if( index < list->size )
    {
        if( before == NULL )
            item = gListl_pollFirst(list);
        else
        {
            node = NULL;
            gSimpleNodeLink_remove(before, &node);
            (list->size)--;
            item = node->e;

            if( before->next == NULL)
                list->end = before;

            gSimpleNodeLink_free(&node);      
        }
    }
    return item;
}

bool gListl_contain( gList_l *list, gElement_t e, bool (*compare)( gElement_t e1, gElement_t e2))
{
    bool contain = false;
    gSimpleLinkNode *node = list->head;;

    while( node != NULL && !contain )
    {
        contain = compare( e, node->e);
        node = node->next;
    }
    return contain;
}

void gListl_removeFirst( gList_l *list, void (*free)( gElement_t *e))
{
    gSimpleLinkNode *node = gListl_p_removeFirst(list);

    if( node != NULL )
    {
        free(&node->e);
        gSimpleNodeLink_free(&node);
    }
}

void gListl_removeLast( gList_l *list, void (*free)( gElement_t *e))
{
    gSimpleLinkNode *node = gListl_p_removeLast(list);

    if( node != NULL )
    {
        free(&node->e);
        gSimpleNodeLink_free(&node);
    }
}

void gListl_removeElement( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2), void (*free)( gElement_t *e))
{
    gSimpleLinkNode *node = list->head;
    gSimpleLinkNode *before = NULL;
    size_t index = 0UL;

    while( node != NULL && !find(node->e, e) )
    {
        index++;
        before = node;
        node = node->next;
    }

    if( index < list->size )
    {
        if( before == NULL )
            gListl_removeFirst(list, free);
        else
        {
            node = NULL;

            gSimpleNodeLink_remove(before, &node);
            (list->size)--;
            free(&(node->e));

            if( before->next == NULL)
                list->end = before;

            gSimpleNodeLink_free(&node);      
        }
    }
}

void gListl_display( gList_l *list, void (*display)( gElement_t e))
{
    gSimpleLinkNode *node = NULL;

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

void gListl_clear( gList_l *list, void (*free)( gElement_t *e))
{
    gSimpleLinkNode *node = list->head;
    gSimpleLinkNode *tmp = NULL;
    
    while (node != NULL )
    {
        tmp = node;
        node = node->next;
        free(&tmp->e);
        gSimpleNodeLink_free(&tmp);
    }
    list->head = list->end = NULL;   
}

void gListl_clearNode( gList_l *list)
{
    gSimpleLinkNode *node = list->head;
    gSimpleLinkNode *tmp = NULL;

    while (node != NULL )
    {
        tmp = node;
        tmp->e = NULL;
        node = node->next;
        gSimpleNodeLink_free(&tmp);
    }
    list->head = list->end = NULL;   
}