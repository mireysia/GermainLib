#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "germainLib/collection/list/stack.h"
#include "germainLib/collection/tree/binaryTree.h"

BinaryTree binaryTree_new(void)
{
    binaryTree* tree = NULL;

    tree = (binaryTree*)malloc(sizeof(binaryTree));

    if( tree != NULL )
    {
        tree->root = NULL;
    }
    return tree;
}

binaryTree_node* binarytree_node_new(void)
{
    binaryTree_node *node = NULL;

    node = (binaryTree_node*)malloc(sizeof(binaryTree_node*));

    if( node != NULL )
    {
        node->item = NULL;
        node->left = node->right = NULL;
    }
    return node;
}

void binaryTree_node_free(binaryTree_node **node)
{
    if( *node != NULL )
    {
        (*node)->item = NULL;
        (*node)->left = (*node)->right = NULL;

        free(*node);
        *node = NULL;
    }
}

void binaryTree_display_prefixe(binaryTree_node *node, void (*display_function)(void *item))
{
    if( node != NULL )
    {
        display_function(node->item);
        binaryTree_display_prefixe(node->left, display_function);
        binaryTree_display_prefixe(node->right, display_function);
    }
}

void binaryTree_display_infixe(binaryTree_node *node, void (*display_function)(void *item))
{
    if( node != NULL )
    {
        binaryTree_display_prefixe(node->left, display_function);
        display_function(node->item);
        binaryTree_display_prefixe(node->right, display_function);
    }
}

void binaryTree_display_postfixe(binaryTree_node *node, void (*display_function)(void *item))
{
    if( node != NULL )
    {
        binaryTree_display_prefixe(node->left, display_function);
        binaryTree_display_prefixe(node->right, display_function);
        display_function(node->item);
    }
}

void binarytree_display(BinaryTree tree, displayMode mode, void (*display_function)(void *item))
{
    switch (mode)
    {
        case PRE_FIXE:
            binaryTree_display_prefixe(tree->root, display_function);
            break;
        case IN_FIXE:
            binaryTree_display_prefixe(tree->root, display_function);
            break;
        case POST_FIXE:
            binaryTree_display_prefixe(tree->root, display_function);
    }
}

bool binaryTree_isLeaf(binaryTree_node *node)
{
    if( node->left == NULL && node->right == NULL)
        return true;
    return false;
}

void binaryTree_insertNode(binaryTree_node **node, void *item, bool (*compare_function)(void *item_1, void *item_node))
{
    binaryTree_node *newNode = *node;
    if( newNode == NULL )
    {
        newNode = binarytree_node_new();
        newNode->item = item;
    }
    else
    {
        if( compare_function(item, newNode->item) )
            binaryTree_insertNode(&(newNode->left), item, compare_function);
        else
            binaryTree_insertNode(&(newNode->right), item, compare_function);
    }
    *node = newNode;
}

void binaryTree_insert(BinaryTree tree, void *item, bool (*compare_function)(void *item_1, void *item_node))
{
    binaryTree_insertNode(&(tree->root), item, compare_function);
}

void binaryTree_ml_insert(BinaryTree tree, void *item, bool (*compare_function)(void *item_1, void *item_node))
{
    Stack stack = stack_alloc();
    stack_push(stack, tree->root);
    binaryTree_node *node = NULL;

    while( !stack_isEmpty(stack) )
    {
        node = (binaryTree_node*)stack_pop(stack);
        if( node == NULL )
        {
            node = binarytree_node_new();
            node->item = item;
        }
        else if( compare_function(item, node->item) )
            stack_push(stack, node->left);
        else
            stack_push(stack, node->right);
    }
}