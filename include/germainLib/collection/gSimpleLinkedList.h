#ifndef __G_SIMPLE_LINKED_LIST_H__
#define __G_SIMPLE_LINKED_LIST_H__

#include <stdlib.h>
#include <stdbool.h>

#include "utils/gSimpleLinkNode.h"
#include "../utils/gElement.h"

typedef struct _G_LINKED_LIST_L gList_l;
typedef gList_l* GList_l;

struct _G_LINKED_LIST_L
{
    size_t size;
    gSimpleLinkNode *head;
    gSimpleLinkNode *end;
};

/**
 * @brief 
 * 
 * @return gList_l* 
 */
gList_l* gListl_new(void);

/**
 * @brief 
 * 
 * @param list 
 */
void gListl_free( gList_l **list);

/**
 * @brief 
 * 
 * @param list 
 * @return true 
 * @return false 
 */
bool gListl_isEmpty( gList_l *list);

/**
 * @brief 
 * 
 * @param list 
 * @return size_t 
 */
size_t gListl_size( gList_l *list);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 */
void gListl_addFirst(  gList_l *list, gElement_t e);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 */
void gListl_addLast( gList_l *list, gElement_t e);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param index 
 */
void gListl_addIndexe( gList_l *list, gElement_t e, const size_t index);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param compare 
 */
void gListl_add( gList_l *list, gElement_t e, bool (*compare)( gElement_t e1, gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param index 
 * @return gElement_t 
 */
gElement_t gListl_get( const gList_l *list, const size_t index);

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListl_getFirst( const gList_l *list);

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListl_getLast( const gList_l *list);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @return gElement_t 
 */
gElement_t gListl_getElement( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @return size_t 
 */
size_t gListl_indexOf( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @return size_t 
 */
size_t gListl_lastIndexOf( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListl_pollFirst( gList_l *list);

/**
 * @brief 
 * 
 * @param list 
 * @return gElement_t 
 */
gElement_t gListl_pollLast( gList_l *list);

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @return gElement_t 
 */
gElement_t gListl_pollElement( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param compare 
 * @return true 
 * @return false 
 */
bool gListl_contain( gList_l *list, gElement_t e, bool (*compare)( gElement_t e1, gElement_t e2));

/**
 * @brief 
 * 
 * @param list 
 * @param free 
 */
void gListl_removeFirst( gList_l *list, void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 * @param free 
 */
void gListl_removeLast( gList_l *list, void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 * @param e 
 * @param find 
 * @param free 
 */
void gListl_removeElement( gList_l *list, gElement_t e, bool (*find)( gElement_t e1, gElement_t e2), void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 * @param display 
 */
void gListl_display( gList_l *list, void (*display)( gElement_t e));

/**
 * @brief 
 * 
 * @param list 
 * @param free 
 */
void gListl_clear( gList_l *list, void (*free)( gElement_t *e));

/**
 * @brief 
 * 
 * @param list 
 */
void gListl_clearNode( gList_l *list);

#endif