#ifndef __G_STACK_H__
#define __G_STACK_H__

#include <stdlib.h>
#include <stdbool.h>

#include "utils/gSimpleLinkNode.h"
#include "../utils/gCompare.h"
#include "../utils/gElement.h"

typedef struct _G_STACK gStack;

typedef gStack* GStack;

struct _G_STACK
{
    size_t size;
    gSimpleLinkNode *node;
};

gStack* gStack_new(void);

void gStack_free( gStack* *stack);

bool gStack_empty( gStack* stack);

gElement_t gStack_peek( gStack* stack);

gElement_t gStack_pop( gStack* stack);

void gStack_push( gStack* stack, gElement_t e);

/* TO DO */
int gStack_search( gStack* stack, gElement_t e, compare compareFunction);

#endif