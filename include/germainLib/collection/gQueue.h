#ifndef __G_QUEUE_H__
#define __G_QUEUE_H__

#include <stdlib.h>

#include "utils/gDoubleLinkNode.h"

typedef struct _G_QUEUE gQueue;

struct gQueue
{
    size_t size;
    gDoubleLinkNode *prev;
    gDoubleLinkNode *next;
};

gQueue* gQueue_new(void);

void gQueue_free( gQueue **queue);

#endif