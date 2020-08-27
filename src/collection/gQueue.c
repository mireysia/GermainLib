#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/gQueue.h"

gQueue* gQueue_new(void)
{
    gQueue *queue = NULL;

    queue = (gQueue*)malloc(sizeof(gQueue));

    if( queue != NULL)
    {
        queue->size = 0UL;
        queue->tail = NULL;
        queue->head = NULL;
    }
    return queue;
}

void gQueue_free( gQueue **queue)
{
    if( *queue != NULL )
    {
        (*queue)->head = NULL;
        (*queue)->tail = NULL;

        free(*queue);
        *queue = NULL;
    }
}

void gQueue_enqueue( gQueue *queue, gElement_t e)
{
    if( queue == NULL || e == NULL) return;
    
    gDoubleLinkNode *node = gDoubleLinkNode_new();

    if(node != NULL)
    {
        node->e = e;

        if( queue->head == NULL && queue->tail == NULL )  
            queue->tail = node;

        gDoubleLinkNode_headInsert( &(queue->head), node);

        (queue->size)++; 
    }
}

gElement_t gQueue_dequeue( gQueue *queue)
{
    if( queue == NULL && gQueue_isEmpty( queue) ) return NULL;

    gDoubleLinkNode *node = NULL;
    gElement_t e = NULL;

    if( queue->size == 1)
        gDoubleLinkNode_headRemove( &(queue->head), &node);
    else
        gDoubleLinkNode_remove( queue->tail, &node);

    queue->tail = node->prev;
    (queue->size)--;
    e = node->e;

    gDoubleLinkNode_free( &node);

    return e;
}

gElement_t gQueue_peek( gQueue *queue)
{
    if( queue == NULL && gQueue_isEmpty(queue) ) return NULL;

    return queue->tail->e;
}

bool gQueue_isEmpty( gQueue *queue)
{
    if( queue->size == 0 ) return true;
    return false;
}

const long long gQueue_getSize( gQueue *queue)
{
    if( queue == NULL ) return -1;

    return queue->size;
}

void gQueue_clear( gQueue *queue, void (*free)( gElement_t *e))
{
    gDoubleLinkNode *node = queue->head;
    gDoubleLinkNode *node_free = NULL;

    while( queue->head != NULL )
    {
        gDoubleLinkNode_headRemove(&(queue->head), &node_free);
        
        queue->tail = node_free->prev;
        (queue->size)--;
        
        free( &(queue->head->e));
        gDoubleLinkNode_free( &node_free);
    }}

void gQueue_display( gQueue *queue, void (*display)( gElement_t e))
{
    gDoubleLinkNode *node = queue->tail;

    while( node != NULL )
    {
        display( node->e);
        node = node->prev;
    }
}

/*
    THREADABLE QUEUE
*/

gQueue_pthd* gQueueThread_new(void)
{
    gQueue_pthd *queue_pthd = NULL;

    queue_pthd = (gQueue_pthd*)malloc(sizeof(gQueue_pthd));

    if( queue_pthd != NULL )
    {
        queue_pthd->size = 0UL;
        queue_pthd->tail = NULL;
        queue_pthd->head = NULL;
        pthread_mutexattr_init( &(queue_pthd->mutex_attr));
        pthread_mutexattr_settype( &(queue_pthd->mutex_attr), PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init( &(queue_pthd->mutex), &(queue_pthd->mutex_attr));
        pthread_cond_init( &(queue_pthd->condition), NULL);
    }     
    return queue_pthd;
}

void gQueueThread__free( gQueue_pthd **queue)
{
    if( *queue != NULL )
    {
        pthread_mutexattr_destroy(&((*queue)->mutex_attr));
        pthread_mutex_destroy(&((*queue)->mutex));
        pthread_cond_destroy(&((*queue)->condition));
        
        (*queue)->head = NULL;
        (*queue)->tail = NULL;

        free(*queue);
        *queue = NULL;
    }
}

void gQueueThread_enqueue( gQueue_pthd *queue, gElement_t e)
{
    if( queue == NULL || e == NULL) return;

    gDoubleLinkNode *node = gDoubleLinkNode_new();

    if(node == NULL) return;

    node->e = e;

    pthread_mutex_lock( &(queue->mutex));

    if( queue->head == NULL && queue->tail == NULL )  
        queue->tail = node;

    gDoubleLinkNode_headInsert(&(queue->head), node);

    (queue->size)++; 
    
    pthread_cond_signal( &(queue->condition));
    pthread_mutex_unlock( &(queue->mutex));
}

gElement_t gQueueThread_dequeue( gQueue_pthd *queue)
{
    if( queue == NULL ) return NULL;

    gDoubleLinkNode *node = NULL;
    gElement_t e = NULL;

    pthread_mutex_lock( &(queue->mutex));

    while( gQueueThread_isEmpty( queue) )
        pthread_cond_wait( &(queue->condition), &(queue->mutex));

    if( queue->size == 1)
        gDoubleLinkNode_headRemove(&(queue->head), &node);
    else
        gDoubleLinkNode_remove(queue->tail, &node);

    queue->tail = node->prev;
    (queue->size)--;
    e = node->e;

    pthread_mutex_unlock( &(queue->mutex));
    gDoubleLinkNode_free(&node);

    return e;
}

bool gQueueThread_isEmpty( gQueue_pthd *queue)
{
    bool isEmpty = false;

    pthread_mutex_lock( &(queue->mutex));

    isEmpty =  queue->size == 0;

    pthread_mutex_unlock( &(queue->mutex));

    return isEmpty;
}