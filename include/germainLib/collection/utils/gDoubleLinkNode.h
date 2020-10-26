#ifndef __G_DOUBLE_LINK_NODE_H__
#define __G_DOUBLE_LINK_NODE_H__

#include "../../utils/gElement.h"

typedef struct _G_DOUBLE_LINK_NODE gDoubleLinkNode;

struct _G_DOUBLE_LINK_NODE
{
    gElement_t e;
    struct _G_DOUBLE_LINK_NODE *next;
    struct _G_DOUBLE_LINK_NODE *prev;
};

/**
 * @brief 
 * 
 * @return gDoubleLinkNode* 
 */
gDoubleLinkNode* gDoubleLinkNode_new(void);

/**
 * @brief 
 * 
 * @param node 
 */
void gDoubleLinkNode_free( gDoubleLinkNode **node);

/**
 * @brief 
 * 
 * @param head 
 * @param insert 
 */
void gDoubleLinkNode_headInsert( gDoubleLinkNode **head, gDoubleLinkNode *insert);

/**
 * @brief 
 * 
 * @param head 
 * @param remove 
 */
void gDoubleLinkNode_headRemove( gDoubleLinkNode **head, gDoubleLinkNode **remove);

/**
 * @brief 
 * 
 * @param node 
 * @param insert 
 */
void gDoubleLinkNode_insert( gDoubleLinkNode *node, gDoubleLinkNode *insert);

/**
 * @brief 
 * 
 * @param node 
 * @param remove 
 */
void gDoubleLinkNode_remove( gDoubleLinkNode *node, gDoubleLinkNode **remove);

/**
 * @brief 
 * 
 * @param remove 
 */
void gDoubleLinkNode_remove_simplify( gDoubleLinkNode *remove);

#endif