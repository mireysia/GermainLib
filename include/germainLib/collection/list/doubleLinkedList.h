/**
 * @author ANTUNES Rémi
 */
#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

#include <stdbool.h>

#include "node_doublelink.h"

#define LIST_NULL_OBJECT -1
#define LIST_ERROR 0
#define LIST_SUCCESS 1

typedef struct _LINKED_LIST_LL list_ll;
typedef list_ll* List_ll;
typedef struct _LINKED_LIST_LL_ITERATOR iterator_ll;

struct _LINKED_LIST_LL_ITERATOR
{
    size_t index;
    node_doubleLink *iterator;
};

struct _LINKED_LIST_LL
{
    size_t nodeNumber;
    node_doubleLink *head;
    node_doubleLink *end;
    iterator_ll *it;
};

/**
 * @brief Constructs an empty list
 * 
 * @return List_l empty list allocated in memory
 */
List_ll list_ll_new(void);

/**
 * @brief frees the list structure in memory
 * 
 * @param list  list frees
 */
void list_ll_free(List_ll *list);

/**
 * @brief Returns the number of elements in this lis
 * 
 * @param list linked list
 * @return unsigned int the number of elements in this lis
 */
unsigned int list_ll_size(List_ll list);

/**
 * @brief Returns true if this collection contains the specified element
 * 
 * @param list linked list
 * @return true 
 * @return false 
 */
bool list_ll_isEmpty(List_ll list);

/**
 * @brief Inserts the specified element at the beginning of this list
 * 
 * @param list linked list
 * @param item the element to add
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_ll_addFirst(List_ll list, void *item);

/**
 * @brief Appends the specified element to the end of this list
 * 
 * @param list linked list
 * @param item the element to add
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_ll_addLast(List_ll list, void *item);

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
int list_ll_addIndexe(List_ll list, void *item, const unsigned int index);

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
int list_ll_add(List_ll list, void *item, bool (*compare_function)(void* item, void* itemNode));

/**
 * @brief Returns the element at the specified position in this list
 * 
 * @param list linked list
 * @param index index of the element to return
 * @return void* the element at the specified position in this list
 */
void* list_ll_get(const List_ll list, const unsigned int index);

/**
 * @brief Returns the first element in this list
 * 
 * @param list linked list
 * @return void* the first element in this list
 * @return NULL any element in this list
 */
void* list_ll_getFirst(const List_ll list);

/**
 * @brief Returns the last element in this list
 * 
 * @param list linked list
 * @return void* the first element in this list
 * @return NULL any element in this list
 */
void* list_ll_getLast(const List_ll list);

void* list_ll_getElement(List_ll list, void *item, bool (*find_function)(void *item1, void *item2));

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
int list_ll_indexOf(List_ll list, void *item, bool (*find_function)(void *item1, void *item2));

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
int list_ll_lastIndexOf(List_ll list, void *item, bool (*find_function)(void *item1, void *item2));

/**
 * @brief Retrieves and removes the first element of this list, 
 * or returns null if this list is empty
 * 
 * @param list linked list
 * @return void* the first element of this list, or null if this list is empty
 */
void* list_ll_pollFirst(List_ll list);

/**
 * @brief Retrieves and removes the last element of this list, 
 * or returns null if this list is empty.
 * 
 * @param list linked list
 * @return void* the first element of this list, or null if this list is empty
 */
void* list_ll_pollLast(List_ll list);

/**
 * @brief Retrieves and removes the element searched in this list, 
 * or returns null if this list is empty.
 * 
 * @param list linked list
 * @param item element to search for in the list
 * @param find_function function performing the comparison to find the good element
 * @return void* the element of this list, or null if this list is empty
 */
void* list_ll_pollElement(List_ll list, void *item, bool (*find_function)(void *item1, void *item2));

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
bool list_ll_contain(List_ll list, void *item, bool (*contain_funcion)(void *item1, void *item2));

/**
 * @brief Removes the first element from this list
 * 
 * @param list linked list
 * @param free_function function deleting element in memory
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_ll_removeFirst(List_ll list, void (*free_function)(void **item));

/**
 * @brief Removes the last element from this list
 * 
 * @param list linked list
 * @param free_function function deleting element in memory
 * @return LIST_ERROR problem to insert the element
 * @return LIST_SUCCESS successful insertion
 */
int list_ll_removeLast(List_ll list, void (*free_function)(void **item));

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
int list_ll_removeElement(List_ll list, void *item, bool (*find_function)(void *item1, void *item2), void (*free_function)(void **item));

/**
 * @brief displays all the elements present in the list
 * 
 * @param list linked list
 * @param display_function function displaying element of the list
 */
void list_ll_display(List_ll list, void (*display_function)(void *item));

/**
 * @brief Removes all of the elements from this list. 
 * The list will be empty after this call returns
 * 
 * @param list linked list
 * @param free_function function deleting element in memory
 */
void list_ll_clear(List_ll list, void (*free_function)(void **item));

void list_ll_iterator_new(List_ll list);

bool list_ll_iterator_next(List_ll list);

void *list_ll_iterator_get(List_ll list);

int list_ll_iterator_index(List_ll list);

void list_ll_it_iterator_free(List_ll list);

bool list_ll_iterator(List_ll list);

int list_ll_iterator_jump(List_ll list);

void *list_ll_iterator_getNext(List_ll list);

#endif