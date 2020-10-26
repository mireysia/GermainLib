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

/**
 * @brief 
 * 
 * @return gList_ll* 
 */
gList_ll* gListll_new(void);

/**
 * @brief 
 * 
 * @param list 
 */
void gListll_free( gList_ll **list);

/**
 * @brief 
 * 
 * @param list 
 * @return true 
 * @return false 
 */
bool gListll_isEmpty( gList_ll *list);

/**
 * @brief 
 * 
 * @param list 
 * @return size_t 
 */
size_t gListll_size( gList_ll *list);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 */
void gListll_addFirst(  gList_ll *list, gElement_t e);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 */
void gListll_addLast( gList_ll *list, gElement_t e);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param index 
 */
void gListll_addIndexe( gList_ll *list, gElement_t e, const size_t index);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param compare 
 */
void gListll_add( gList_ll *list, gElement_t e, bool (*compare)( const gElement_t e1, const gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param index 
 * @return gElement_t 
 */
gElement_t gListll_get( const gList_ll *list, const size_t index);

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListll_getFirst( const gList_ll *list);

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListll_getLast( const gList_ll *list);

/**
 * @brief 
 * 
 * @param list 
 * @param item 
 * @param find 
 * @return gElement_t 
 */
gElement_t gListll_getElement( gList_ll *list, gElement_t item, bool (*find)( const gElement_t e1, const gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @return size_t 
 */
size_t gListll_indexOf( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @return size_t 
 */
size_t gListll_lastIndexOf( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListll_pollFirst( gList_ll *list);

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListll_pollLast( gList_ll *list);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @return gElement_t 
 */
gElement_t gListll_pollElement( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1, const gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param compare 
 * @return true 
 * @return false 
 */
bool gListll_contain( gList_ll *list, gElement_t e, bool (*compare)( const gElement_t e1, const gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param free 
 */
void gListll_removeFirst( gList_ll *list, void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 * @param free 
 */
void gListll_removeLast( gList_ll *list, void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @param free 
 */
void gListll_removeElement( gList_ll *list, gElement_t e, bool (*find)( const gElement_t e1,const  gElement_t e2), void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 * @param display 
 */
void gListll_display( gList_ll *list, void (*display)( const gElement_t e));

/**
 * @brief 
 * 
 * @param list 
 * @param free 
 */
void gListll_clear( gList_ll *list, void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 */
void gListll_clearNode( gList_ll *list);

#endif