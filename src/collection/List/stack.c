/**
 * @author ANTUNES Rémi
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "germainLib/collection/list/node_simplelink.h"
#include "germainLib/collection/list/stack.h"

Stack stack_alloc(void)
{
    stack *_stack = NULL;

    _stack = (stack*)malloc(sizeof(stack));

    if( _stack != NULL )
    {
        _stack->number_node = 0;
        _stack->limit_node = STACK_LIMIT_NODE;
        _stack->head_node = NULL;
    }
    return _stack;
}

void stack_free(Stack *stack)
{
    if( *stack != NULL )
    {
        (*stack)->head_node = NULL;
        free(*stack);
        *stack = NULL;
    }
}

bool stack_isEmpty(Stack stack)
{
    if(stack->number_node == 0)
        return true;
    return false;
}

bool stack_isFull(Stack stack)
{
    if(stack->number_node == stack->limit_node)
        return true;
    return false;
}

int stack_push(Stack stack, void *item)
{
    if( stack == NULL || item == NULL || stack_isFull(stack) )
        return STACK_ERROR;


    node_oneLink* node = nodeSimpleLink_alloc();
        
    node->item = item;
    nodeSimpleLink_headInsert(&(stack->head_node), node);
    (stack->number_node)++;

    return STACK_SUCCESS;    
}

void* stack_pop(Stack stack)
{
    if( stack == NULL || stack_isEmpty(stack) )
        return STACK_ERROR;
   
    node_oneLink *remove = NULL;
    void* item = NULL;

    nodeSimpleLink_headRemove(&(stack->head_node), &remove);
    (stack->number_node)--;
    item = remove->item;
    nodeSimpleLink_free(&remove);

    return item;
}

bool stack_contains(const Stack stack, void *items, bool (*compare_function)(void *variable_one, void *variable_two))
{
    bool verification = false;
    node_oneLink *node = stack->head_node;

    while( node != NULL && !verification )
    {
        verification = compare_function(items, node->item);
        node = node->next;
    }
    return verification;
}

void stack_display(Stack stack, void (*display_function)(void *item))
{
    node_oneLink *node = stack->head_node;

    while( node != NULL )
    {
        display_function(node->item);
        node = node->next;
    }
}