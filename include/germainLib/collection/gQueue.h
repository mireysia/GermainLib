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

/**
 * @brief 
 * 
 * @return gQueue* 
 */
gQueue* gQueue_new(void);

/**
 * @brief 
 * 
 * @param queue 
 */
void gQueue_free( gQueue **queue);

/**
 * @brief 
 * 
 * @param queue 
 * @param e 
 */
void gQueue_enqueue( gQueue *queue, gElement_t e);

/**
 * @brief 
 * 
 * @param queue 
 * @return gElement_t 
 */
gElement_t gQueue_dequeue( gQueue *queue);

/**
 * @brief 
 * 
 * @param queue 
 * @return gElement_t 
 */
gElement_t gQueue_peek( gQueue *queue);

/**
 * @brief 
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool gQueue_isEmpty( gQueue *queue);

/**
 * @brief 
 * 
 * @param queue 
 * @return const long long 
 */
const long long gQueue_getSize( gQueue *queue);

/**
 * @brief 
 * 
 * @param queue 
 * @param free 
 */
void gQueue_clear( gQueue *queue, void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param queue 
 * @param display 
 */
void gQueue_display( gQueue *queue, void (*display)( gElement_t e));

/*
    THREADABLE QUEUE
*/

/**
 * @brief 
 * 
 * @return gQueue_pthd* 
 */
gQueue_pthd* gQueueThread_new(void);

/**
 * @brief 
 * 
 * @param queue 
 */
void gQueueThread__free( gQueue_pthd **queue);

/**
 * @brief 
 * 
 * @param queue 
 * @param e 
 */
void gQueueThread_enqueue( gQueue_pthd *queue, gElement_t e);

/**
 * @brief 
 * 
 * @param queue 
 * @return gElement_t 
 */
gElement_t gQueueThread_dequeue( gQueue_pthd *queue);

/**
 * @brief 
 * 
 * @param queue 
 * @return true 
 * @return false 
 */
bool gQueueThread_isEmpty( gQueue_pthd *queue);

#endif