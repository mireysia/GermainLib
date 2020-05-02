/**
 * @author ANTUNES Rémi
 */
#ifndef __STACK_H__
#define __STACK_H__

#include <stdbool.h>
#include "node_simplelink.h"

#define STACK_ERROR 0
#define STACK_SUCCESS 1

#define STACK_SWAP_MINIMUM 2
#define STACK_LIMIT_NODE 1000

typedef struct _STACK stack;

typedef stack* Stack;

/**
 * @brief structure pile
 * - nombre d'element dans la pile
 * - pointeur vers le premier element de la pile
 */
struct _STACK
{
    size_t limit_node;
    size_t number_node;
    node_oneLink *head_node;
};

/**
 * @brief alloue en memoire une strcuture stack
 * - nombre de maillon a 0
 * - pointeur tete de pile NULL
 *
 * @return Stack structure Stack allouee
 */
Stack stack_alloc(void);

/**
 * @brief libere en memoire une variable de type stack
 * 
 * @param stack variable de Stack liberee
 */
void stack_free(Stack *stack);

/**
 * @brief verifie si la pile est vide
 * 
 * @param stack pointeur pile
 * @return true pile vide
 * @return false pile contenant de la data
 */
bool stack_isEmpty(Stack stack);

/**
 * @brief ajoute une donnée dans la pile
 * 
 * @param stack pointeur pile
 * @param items donnee a inserer dans la pile
 * @return STACK_ERROR ( 0 ) : erreur pointeur stack NULL
 * @return STACK_DATA_NULL ( 2 ) : pointeur items NULL 
 * @return STACK_SUCCESS ( 1 ) : insertion reussite
 */
int stack_push(Stack stack, void *item);

/**
 * @brief retire une donnee de la pile
 * 
 * @param stack pointeur pile
 * @return void* donnée recuperer dans la pile ( NULL si erreur)
 */
void* stack_pop(Stack stack);

/**
 * TO DO 
 */
int stack_swap(Stack stack);

void stack_display(Stack stack, void (*display_function)(void *item));

int stack_getSize(Stack stack);

int stack_setSizeLimit(Stack stack, size_t stackSize);

int stack_getSizeLimit(Stack stack);

bool stack_contains(const Stack stack, void *items, bool (*compare_function)(void *variable_one, void *variable_two));

#endif 