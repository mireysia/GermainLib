/**
 * @author ANTUNES Rémi
 */
#ifndef __NODE_DOUBLELINK__
#define __NODE_DOUBLELINK__

typedef struct _NODE_DOUBLE_LINK node_doubleLink;

struct _NODE_DOUBLE_LINK
{
    void *item;
    node_doubleLink *next;
    node_doubleLink *prev;
};

/**
 * @brief alloue en memoire une structure node_doubleLink
 * 
 * @return node_doubleLink* node alloue
 */
node_doubleLink* nodeDoubleLink_alloc(void);

/**
 * @brief 
 * 
 * @param node 
 */
void nodeDoubleLink_free(node_doubleLink **node);

/**
 * @brief 
 * 
 * @param head 
 * @param insert 
 */
void nodeDoubleLink_headInsert(node_doubleLink **head, node_doubleLink *insert);

/**
 * @brief 
 * 
 * @param head 
 * @param remove 
 */
void nodeDoubleLink_headRemove(node_doubleLink **head, node_doubleLink **remove);

/**
 * @brief 
 * 
 * @param node 
 * @param insert 
 */
void nodeDoubleLink_insert(node_doubleLink *node, node_doubleLink *insert);

/**
 * @brief 
 * 
 * @param node 
 * @param remove 
 */
void nodeDoubleLink_remove(node_doubleLink *node, node_doubleLink **remove);

/**
 * @brief 
 * 
 * @param firstNode 
 * @param secondNode 
 */
void nodeDoubleLink_swapNode(node_doubleLink *firstNode, node_doubleLink *secondNode);

#endif