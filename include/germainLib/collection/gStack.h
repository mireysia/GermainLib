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

/**
 * @brief 
 * 
 * @return gStack* 
 */
gStack* gStack_new(void);

/**
 * @brief 
 * 
 * @param stack 
 */
void gStack_free( gStack* *stack);

/**
 * @brief 
 * 
 * @param stack 
 * @return true 
 * @return false 
 */
bool gStack_empty( gStack* stack);

/**
 * @brief 
 * 
 * @param stack 
 * @return gElement_t 
 */
gElement_t gStack_peek( gStack* stack);

/**
 * @brief 
 * 
 * @param stack 
 * @return gElement_t 
 */
gElement_t gStack_pop( gStack* stack);

/**
 * @brief 
 * 
 * @param stack 
 * @param e 
 */
void gStack_push( gStack* stack, gElement_t e);

/* TO DO */
int gStack_search( gStack* stack, gElement_t e, compare compareFunction);

#endif