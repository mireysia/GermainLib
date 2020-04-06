/**
 * @author ANTUNES Rémi
 */
#ifndef __SIMPLELINKEDLIST_H__
#define __SIMPLELINKEDLIST_H__

#include <stdbool.h>
#include "node_simplelink.h"

#define LIST_ERROR 0
#define LIST_SUCCESS 1

typedef struct _LINKED_LIST_L list_l;

typedef list_l* List_l;

struct _LINKED_LIST_L
{
    size_t nodeNumber;
    node_oneLink *head;
    node_oneLink *end;
};

List_l list_l_alloc(void);
void list_l_free(List_l *list);
unsigned int list_l_size(List_l list);
bool list_l_isEmpty(List_l list);
void list_l_searchIndexe(node_oneLink *head, const int indexe, node_oneLink **nodeSearch);
int list_l_addFirst(List_l list, void *item);
int list_l_add(List_l list, void *item);
unsigned int list_l_indexOf(List_l list, void *item, bool (*find_function)(void *item1, void *item2));
void* list_l_get(const List_l list, const unsigned int indexe);
void* list_l_pollFirst(List_l list);
bool list_l_contain(List_l list, void *item, bool (*contain_funcion)(void *item1, void *item2));
void* list_l_findElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2));
void list_l_display(List_l list, void (*display_function)(void *item));
void list_l_clear(List_l list);

#endif