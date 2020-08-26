#ifndef __G_SIMPLE_LINK_NODE_H__
#define __G_SIMPLE_LINK_NODE_H__

#include "../../utils/gElement.h"

typedef struct _G_SIMPLELINK_NODE gSimpleLinkNode;

struct _G_SIMPLELINK_NODE 
{
    gElement_t e;
    struct _G_SIMPLELINK_NODE *next;
};

/**
 * @brief 
 * 
 * @return gSimpleNode* 
 */
gSimpleLinkNode* gSimpleNodeLink_new(void);

/**
 * @brief 
 * 
 * @param node 
 */
void gSimpleNodeLink_free( gSimpleLinkNode **node);

/**
 * @brief 
 * 
 * @param head 
 * @param insert 
 */
void gSimpleNodeLink_headInsert( gSimpleLinkNode **head, gSimpleLinkNode *insert);

/**
 * @brief 
 * 
 * @param head 
 * @param remove 
 */
void gSimpleNodeLink_headRemove( gSimpleLinkNode **head, gSimpleLinkNode **remove);

/**
 * @brief 
 * 
 * @param node 
 * @param insert 
 */
void gSimpleNodeLink_insert( gSimpleLinkNode *node, gSimpleLinkNode *insert);

/**
 * @brief 
 * 
 * @param before 
 * @param remove 
 */
void gSimpleNodeLink_remove( gSimpleLinkNode *before, gSimpleLinkNode **remove);

#endif