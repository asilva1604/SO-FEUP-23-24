#include <stdlib.h>
#include "list.h"

void list_add_first(int val, list *l) {
    node *first = (node*)malloc(sizeof(node));
    first->val = val;
    first->next = l->first;
    l->size++;
}