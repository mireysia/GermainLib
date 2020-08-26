#ifndef __G_DOUBLE_LINKED_LIST_H__
#define __G_DOUBLE_LINKED_LIST_H__

#include <stdlib.h>
#include <stdbool.h>

#include "utils/gDoubleLinkNode.h"
#include "../utils/gElement.h"

typedef struct _G_LINKED_LIST_LL gList_ll;
typedef gList_ll* GList_ll;

struct _G_LINKED_LIST_LL
{
    size_t size;
    gDoubleLinkNode *head;
    gDoubleLinkNode *end;
};

gList_ll* gListll_new(void);

void gListll_free( gList_ll **list);

bool gListll_isEmpty( gList_ll *list);

size_t gListll_size( gList_ll *list);

void gListll_addFirst(  gList_ll *list, gElement_t e);

void gListll_addLast( gList_ll *list, gElement_t e);

void gListll_addIndexe( gList_ll *list, gElement_t e, const size_t index);

void gListll_add( gList_ll *list, gElement_t e, bool (*compare)( gElement_t e1, gElement_t e2));

gElement_t gListll_get( const gList_ll *list, const size_t index);

gElement_t gListll_getFirst( const gList_ll *list);

gElement_t gListll_getLast( const gList_ll *list);

gElement_t gListll_getElement( gList_ll *list, gElement_t item, bool (*find)( gElement_t e1, gElement_t e2));

size_t gListll_indexOf( gList_ll *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2));

size_t gListll_lastIndexOf( gList_ll *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2));

gElement_t gListll_pollFirst( gList_ll *list);

gElement_t gListll_pollLast( gList_ll *list);

gElement_t gListll_pollElement( gList_ll *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2));

bool gListll_contain( gList_ll *list, gElement_t e, bool (*compare)( gElement_t e1, gElement_t e2));

void gListll_removeFirst( gList_ll *list, void (*free)( gElement_t *e));

void gListll_removeLast( gList_ll *list, void (*free)( gElement_t *e));

void gListll_removeElement( gList_ll *list, void *item, bool (*find)( gElement_t e1, gElement_t e2), void (*free)( gElement_t *e));

void gListll_display( gList_ll *list, void (*display)( gElement_t e));

void gListll_clear( gList_ll *list, void (*free)( gElement_t *e));

void gListll_clearNode( gList_ll *list);

#endif