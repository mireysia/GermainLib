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

gDoubleLinkNode* gDoubleLinkNode_new(void);

void gDoubleLinkNode_free( gDoubleLinkNode **node);

void gDoubleLinkNode_headInsert( gDoubleLinkNode **head, gDoubleLinkNode *insert);

void gDoubleLinkNode_headRemove( gDoubleLinkNode **head, gDoubleLinkNode **remove);

void gDoubleLinkNode_insert( gDoubleLinkNode *node, gDoubleLinkNode *insert);

void gDoubleLinkNode_remove( gDoubleLinkNode *node, gDoubleLinkNode **remove);

void gDoubleLinkNode_remove_simplify( gDoubleLinkNode *remove);

#endif