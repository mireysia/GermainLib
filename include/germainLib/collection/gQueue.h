#ifndef __G_QUEUE_H__
#define __G_QUEUE_H__

#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#include "utils/gDoubleLinkNode.h"
#include "../utils/gElement.h"

typedef struct _G_QUEUE gQueue;
typedef struct _G_QUEUE_THREAD gQueue_pthd;

struct _G_QUEUE
{
    size_t size;
    gDoubleLinkNode *head;
    gDoubleLinkNode *tail;
};

struct _G_QUEUE_THREAD
{
    size_t size;
    gDoubleLinkNode *head;
    gDoubleLinkNode *tail;

    pthread_mutex_t mutex;
    pthread_cond_t condition;
    pthread_mutexattr_t mutex_attr;
};

gQueue* gQueue_new(void);

void gQueue_free( gQueue **queue);

void gQueue_enqueue( gQueue *queue, gElement_t e);

gElement_t gQueue_dequeue( gQueue *queue);

gElement_t gQueue_peek( gQueue *queue);

bool gQueue_isEmpty( gQueue *queue);

const long long gQueue_getSize( gQueue *queue);

void gQueue_clear( gQueue *queue, void (*free)( gElement_t *e));

void gQueue_display( gQueue *queue, void (*display)( gElement_t e));

/*
    THREADABLE QUEUE
*/

gQueue_pthd* gQueueThread_new(void);

void gQueueThread__free( gQueue_pthd **queue);

void gQueueThread_enqueue( gQueue_pthd *queue, gElement_t e);

gElement_t gQueueThread_dequeue( gQueue_pthd *queue);

bool gQueueThread_isEmpty( gQueue_pthd *queue);

#endif