#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "germainLib/queue.h"
#include "germainLib/stack.h"

void display(int *val)
{
    printf("val -> %d\n", *(val));
}

void free_int(void **i)
{
    printf("adresse %p\n", *i);
    free(*i);
    *i = NULL;
}
bool contains_items(int *un, int *deux)
{
    if( *un == *deux)
        return true;
    return false;
}

int main(void)
{
    Queue q = queue_alloc();
    int item = 19;
    int item2 = 67;
    int item3 = 99999;

    queue_enqueue(q, &item);

    printf("valeur %d\n", *((int*)(q->head->item)));

    queue_enqueue(q, &item2);

    printf("valeur %d\n", *((int*)(q->head->item)));
    printf("valeur %d\n", *((int*)(q->tail->item)));

    queue_enqueue(q, &item3);
    printf("next\n");
    printf("valeur %d\n", *((int*)(q->head->item)));
    printf("valeur %d\n", *((int*)(q->head->next->item)));
    printf("valeur %d\n", *((int*)(q->head->next->next->item)));
    printf("prev\n");
    printf("valeur tail %d\n", *((int*)(q->tail->item)));
    printf("valeur tail %d\n", *((int*)(q->tail->prev->item)));
    printf("valeur %u\n", *((int*)(q->tail->prev->prev->item)));

    printf("nombre de valeur -> %d\n", q->number_node);
    printf("queue vide -> %d\n", queue_isEmpty(q));

    queue_display(q, display);
    queue_clearAll_normalData(q);
    printf("queue vide -> %d\n", queue_isEmpty(q));
    queue_display(q, display);

    Stack s = stack_alloc();

    int un = 776;
    int deux = 987;
    int trois = 3;
    int items = 9879;
    bool verif;

    stack_push(s, &un);
    stack_display(s, display);
    puts(" ");
    stack_push(s, &deux);
    stack_display(s, display);
    puts(" ");
    stack_push(s, &trois);
    stack_display(s, display);
    puts(" ");
    verif = stack_contains( s, &items, contains_items);
    printf("verif -> %d\n", verif);

    return 0;
}