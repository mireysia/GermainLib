/**
 * @author ANTUNES Rémi
 */
#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>
#include "node_doublelink.h"

#define QUEUE_DEFAULT_SIZE 500

#define QUEUE_ERROR 0
#define QUEUE_SUCCESS 0

typedef struct _QUEUE queue;

typedef queue* Queue;

struct _QUEUE
{
    size_t limit_node;
    size_t number_node;
    node_doubleLink *head;
    node_doubleLink *tail;
};

Queue queue_alloc(void);

void queue_free(Queue *queue);

int queue_enqueue(Queue queue, void* item);

void* queue_dequeue(Queue queue);

void* queue_peek(Queue queue);

bool queue_isFull(Queue queue);

bool queue_isEmpty(Queue queue);

int queue_setSizeLimit(Queue queue, size_t sizeQueue);

int queue_getSizeLimit(Queue queue);

int queue_getSize(Queue queue);

void queue_clearAll_allowedData(Queue queue, void (*free_function)(void**));

void queue_clearAll_normalData(Queue queue);

void queue_display(Queue queue, void (*display_function)(void*));

#endif