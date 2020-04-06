/**
 * @author ANTUNES Rémi
 */
#ifndef __NODE_SIMPLELINK_H__
#define __NODE_SIMPLELINK_H__

typedef struct _NODE_ONE_LINK node_oneLink;

struct _NODE_ONE_LINK
{
    void *item;
    node_oneLink *next;
};

/**
 * @brief 
 * 
 * @return node_oneLink* 
 */
node_oneLink* nodeSimpleLink_alloc(void);

/**
 * @brief 
 * 
 * @param node 
 */
void nodeSimpleLink_free(node_oneLink **node);

/**
 * @brief 
 * 
 * @param head 
 * @param insert 
 */
void nodeSimpleLink_headInsert(node_oneLink **head, node_oneLink *insert);

/**
 * @brief 
 * 
 * @param head 
 * @param remove 
 */
void nodeSimpleLink_headRemove(node_oneLink **head, node_oneLink **remove);

/**
 * @brief 
 * 
 * @param node 
 * @param insert 
 */
void nodeSimpleLink_insert(node_oneLink *node, node_oneLink *insert);

/**
 * @brief 
 * 
 * @param precedent 
 * @param remove 
 */
void nodeSimpleLink_remove(node_oneLink *precedent, node_oneLink **remove);

/**
 * @brief 
 * 
 * @param precedent 
 * @param remove 
 */
void nodeSimpleLink_swap(node_oneLink *precedent, node_oneLink **remove);
#endif