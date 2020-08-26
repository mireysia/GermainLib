#include <stdlib.h>
#include <stdio.h>

#include "germainLib/collection/gStack.h"

gStack* gStack_new(void)
{
    gStack *new = NULL;

    new  = (gStack*)malloc(sizeof(gStack));

    if( new != NULL )
    {
        new->size = 0;
        new->node = NULL;
    }

    return new;
}

void gStack_free( gStack **stack)
{
    if( *stack != NULL )
    {
        (*stack)->node = NULL;

        free( *stack);
        *stack = NULL;
    }
}

bool gStack_empty( gStack* stack)
{
    if( stack->size == 0 )
        return true;
    return false;
}

gElement_t gStack_peek( gStack* stack)
{
    if( stack == NULL ) return NULL;

    gSimpleLinkNode *node = stack->node;
    return node->e;
}

gElement_t gStack_pop( gStack* stack)
{
    if( stack == NULL ) return NULL;

    gSimpleLinkNode *node = NULL;
    gElement_t e = NULL;

    gSimpleNodeLink_headRemove( &(stack->node), &node);
    (stack->size)--;
    e = node->e;
    gSimpleNodeLink_free( &node);

    return e;
}

void gStack_push( gStack* stack, gElement_t e)
{
    if( stack == NULL ) return;

    gSimpleLinkNode *node = gSimpleNodeLink_new();

    node->e = e;

    gSimpleNodeLink_headInsert( &(stack->node), node);
    (stack->size)++;
}