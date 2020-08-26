#include <stdio.h>
#include <stdlib.h>

#include "germainLib/collection/gStack.h"

int main(void)
{
    gStack *stack = gStack_new();
    int v = 23;
    int *a = &v;
    printf("ok ? %p\n", stack);
    gStack_push( stack, a);

    int *b = (int*) gStack_pop( stack);

    gStack_free( &stack);
    printf("ok ? %d\n", *b);
    return 0;
}