/**
 * @author ANTUNES Rémi
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "germainLib/node_doublelink.h"
#include "germainLib/queue.h"

Queue queue_alloc(void)
{
    queue *_queue = NULL;

    _queue = (queue*)malloc(sizeof(queue));

    if(_queue != NULL)
    {
        _queue->number_node = 0;
        _queue->limit_node = QUEUE_DEFAULT_SIZE;
        _queue->tail = _queue->head = NULL;
    }
    return _queue;
}

void queue_free(Queue *queue)
{
    if( *queue != NULL )
    {
        (*queue)->head = NULL;
        (*queue)->tail = NULL;

        free(*queue);
        *queue = NULL;
    }
}

int queue_enqueue(Queue queue, void* item)
{
    if( queue_isFull(queue) || queue == NULL || item == NULL)
        return QUEUE_ERROR;
    
    node_doubleLink *node = nodeDoubleLink_alloc();

    if(node == NULL)
        return QUEUE_ERROR;

    node->item = item;

    if( queue->head == NULL && queue->tail == NULL )  
        queue->tail = node;

    nodeDoubleLink_headInsert(&(queue->head), node);

    (queue->number_node)++;        

    return QUEUE_SUCCESS;
}

void* queue_dequeue(Queue queue)
{
    if( queue == NULL && queue_isEmpty(queue) )
        return NULL;

    node_doubleLink *node = NULL;
    void *item = NULL;

    if( queue->number_node == 1)
        nodeDoubleLink_headRemove(&(queue->head), &node);
    else
        nodeDoubleLink_remove(queue->tail, &node);
    queue->tail = node->prev;
    (queue->number_node)--;
    item = node->item;
    nodeDoubleLink_free(&node);

    return item;
}

void* queue_peek(Queue queue)
{
    if( queue == NULL && queue_isEmpty(queue) )
        return NULL;

    return queue->tail->item;
}

bool queue_isFull(Queue queue)
{
    if( queue->number_node == queue->limit_node )
        return true;
    return false;
}

bool queue_isEmpty(Queue queue)
{
    if( queue->number_node == 0 )
        return true;
    return false;
}

int queue_setSizeLimit(Queue queue, size_t sizeQueue)
{
    if( queue == NULL )
        return QUEUE_ERROR;

    if( queue_isEmpty(queue) )
        return QUEUE_ERROR;

    queue->limit_node = sizeQueue;
    return QUEUE_SUCCESS;
}

int queue_getSizeLimit(Queue queue)
{
    if( queue == NULL )
        return -1;

    return queue->limit_node;
}

int queue_getSize(Queue queue)
{
    if( queue == NULL )
        return -1;

    return queue->number_node;
}

void queue_clearAll_allowedData(Queue queue, void (*free_function)(void**))
{
    node_doubleLink *node = queue->head;
    node_doubleLink *node_free = NULL;

    while( queue->head != NULL )
    {
        nodeDoubleLink_headRemove(&(queue->head), &node_free);
        queue->tail = node_free->prev;
        (queue->number_node)--;
        free_function(&(queue->head->item));
        nodeDoubleLink_free(&node_free);
    }
}

void queue_clearAll_normalData(Queue queue)
{
    node_doubleLink *node = queue->head;
    node_doubleLink *node_free = NULL;

    while( queue->head != NULL )
    {
        nodeDoubleLink_headRemove(&(queue->head), &node_free);
        queue->tail = node_free->prev;
        (queue->number_node)--;
        nodeDoubleLink_free(&node_free);
    }
}

void queue_display(Queue queue, void (*display_function)(void*))
{
    node_doubleLink *node = queue->tail;

    while( node != NULL )
    {
        display_function(node->item);
        node = node->prev;
    }
}