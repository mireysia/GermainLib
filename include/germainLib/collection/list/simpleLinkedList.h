/**
 * @author ANTUNES Rémi
 */
#ifndef __SIMPLELINKEDLIST_H__
#define __SIMPLELINKEDLIST_H__

#include <stdbool.h>
#include "node_simplelink.h"

#define LIST_NULL_OBJECT -1
#define LIST_ERROR 0
#define LIST_SUCCESS 1

typedef struct _LINKED_LIST_L list_l;
typedef list_l* List_l;
typedef struct _LINKED_LIST_L_ITERATOR iterator_l;

struct _LINKED_LIST_L_ITERATOR
{
    size_t index;
    node_oneLink *iterator;
};

struct _LINKED_LIST_L
{
    size_t nodeNumber;
    node_oneLink *head;
    node_oneLink *end;
    iterator_l *it;
};

/**
 * @brief Constructs an empty list
 * 
 * @return List_l empty list allocated in memory
 */
List_l list_l_new(void);

/**
 * @brief frees the list structure in memory
 * 
 * @param list  list frees
 */
void list_l_free(List_l *list);

/**
 * @brief Returns the number of elements in this lis
 * 
 * @param list linked list
 * @return unsigned int the number of elements in this lis
 */
unsigned int list_l_size(List_l list);

/**
 * @brief Returns true if this collection contains the specified element
 * 
 * @param list linked list
 * @return true 
 * @return false 
 */
bool list_l_isEmpty(List_l list);

/**
 * @brief Inserts the specified element at the beginning of this list
 * 
 * @param list linked list
 * @param item the element to add
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_l_addFirst(List_l list, void *item);

/**
 * @brief Appends the specified element to the end of this list
 * 
 * @param list linked list
 * @param item the element to add
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_l_addLast(List_l list, void *item);

/**
 * @brief Inserts the specified element at the specified position in this list. 
 * Shifts the element currently at that position (if any) and any subsequent elements 
 * to the right (adds one to their indices)
 * 
 * @param list linked list
 * @param item telement to be inserted
 * @param index index at which the specified element is to be inserted
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_l_addIndexe(List_l list, void *item, const unsigned int index);

/**
 * @brief Inserts the specified element at the specified position in this list
 * thanks to the unction performing the comparison to find the good position 
 * to add the element.Shifts the element currently at that position (if any) and any subsequent elements 
 * to the right (adds one to their indices)
 * 
 * @param list linked list
 * @param item element to search for in the list
 * @param find_function function performing the comparison to find the good position to add the element
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_l_add(List_l list, void *item, bool (*compare_function)(void* item, void* itemNode));

int list_l_duplicateData_add(List_l list, void *item, void* (duplicate_function)(void* data) ,bool (*compare_function)(void* item, void* itemNode));

/**
 * @brief Returns the element at the specified position in this list
 * 
 * @param list linked list
 * @param index index of the element to return
 * @return void* the element at the specified position in this list
 */
void* list_l_get(const List_l list, const unsigned int index);

/**
 * @brief Returns the first element in this list
 * 
 * @param list linked list
 * @return void* the first element in this list
 * @return NULL any element in this list
 */
void* list_l_getFirst(const List_l list);

/**
 * @brief Returns the last element in this list
 * 
 * @param list linked list
 * @return void* the first element in this list
 * @return NULL any element in this list
 */
void* list_l_getLast(const List_l list);

void* list_l_getElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2));

/**
 * @brief Returns the index of the first occurrence of the specified element 
 * in this list, or -1 if this list does not contain the element.
 * 
 * @param list linked list
 * @param item element to search for in the list
 * @param find_function function performing the comparison to find the good element
 * @return int the index of the first occurrence of the specified element 
 * in this list, or -1 if this list does not contain the element
 */
int list_l_indexOf(List_l list, void *item, bool (*find_function)(void *item1, void *item2));

/**
 * @brief Returns the index of the last occurrence of the specified element 
 * in this list, or -1 if this list does not contain the element
 * 
 * @param list linked list
 * @param item element to search for in the list
 * @param find_function function performing the comparison to find the good element
 * @return int the index of the first occurrence of the specified element 
 * in this list, or -1 if this list does not contain the element
 */
int list_l_lastIndexOf(List_l list, void *item, bool (*find_function)(void *item1, void *item2));

/**
 * @brief Retrieves and removes the first element of this list, 
 * or returns null if this list is empty
 * 
 * @param list linked list
 * @return void* the first element of this list, or null if this list is empty
 */
void* list_l_pollFirst(List_l list);

/**
 * @brief Retrieves and removes the last element of this list, 
 * or returns null if this list is empty.
 * 
 * @param list linked list
 * @return void* the first element of this list, or null if this list is empty
 */
void* list_l_pollLast(List_l list);

/**
 * @brief Retrieves and removes the element searched in this list, 
 * or returns null if this list is empty.
 * 
 * @param list linked list
 * @param item element to search for in the list
 * @param find_function function performing the comparison to find the good element
 * @return void* the element of this list, or null if this list is empty
 */
void* list_l_pollElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2));

/**
 * @brief Returns true if this list contains the specified element. 
 * More formally, returns true if and only if this list contains at 
 * least one element
 * 
 * @param list linked list
 * @param item element to search for in the list
 * @param contain_funcion function performing the comparison to find the good element
 * @return true list contains at least one element 
 * @return false list contains any element of item
 */
bool list_l_contain(List_l list, void *item, bool (*contain_funcion)(void *item1, void *item2));

/**
 * @brief Removes the first element from this list
 * 
 * @param list linked list
 * @param free_function function deleting element in memory
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_l_removeFirst(List_l list, void (*free_function)(void **item));

/**
 * @brief Removes the last element from this list
 * 
 * @param list linked list
 * @param free_function function deleting element in memory
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_l_removeLast(List_l list, void (*free_function)(void **item));

/**
 * @brief Removes the first occurrence of the specified element from this list, 
 * if it is present. If this list does not contain the element.
 *  More formally, removes the element with the lowest index i
 * 
 * @param list linked list
 * @param item element to search for in the list
 * @param find_function function performing the comparison
 * @param free_function function deleting element in memory
 * @return LIST_NULL_OBJECT any element corresponding to the item searched 
 */
int list_l_removeElement(List_l list, void *item, bool (*find_function)(void *item1, void *item2), void (*free_function)(void **item));

/**
 * @brief displays all the elements present in the list
 * 
 * @param list linked list
 * @param display_function function displaying element of the list
 */
void list_l_display(List_l list, void (*display_function)(void *item));

/**
 * @brief Removes all of the elements from this list. 
 * The list will be empty after this call returns
 * 
 * @param list linked list
 * @param free_function function deleting element in memory
 */
void list_l_clear(List_l list, void (*free_function)(void **item));

void list_l_clearAllNode(List_l list);

void list_l_iterator_new(List_l list);

bool list_l_iterator_next(List_l list);

bool list_l_iterator(List_l list);

void *list_l_iterator_get(List_l list);

int list_l_iterator_index(List_l list);

void list_it_iterator_free(List_l list);

#endif