#ifndef __INTEGER_H__
#define __INTEGER_H__

#include <stdbool.h>
#include "germainLib/collection/list/simpleLinkedList.h"

typedef struct _INTEGER_ARRAYS_DYNAMIC integer_arrays_d;
typedef integer_arrays_d* Integer_arrays;

void integer_free(int **integer);

void integer_vt_free(void **integer);

bool integer_vt_compare(void *integer_1, void *integer_2);
bool integer_vt_different(void *integer_1, void *integer_2);

void* integer_duplicateInt(void *integer);

void integer_display(void *intger);

unsigned int integer_arrays_numberOfDifferentInteger(int *intgerTab, const size_t tabSize);

List_l integer_arraysToHashSetList(int *intgerTab, const size_t tabSize);

#endif