#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void list_add_last(int val, list *l) {
    node* p = node_new(val, NULL);
    if (l->size == 0) {
        l->first = p;
        printf("here");
    }else{
    node* q = l->first;
    while (q->next != NULL)
    q = q->next;
    q->next = p;
    }
    l->size++;
}