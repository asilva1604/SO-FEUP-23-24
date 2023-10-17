#include "list.h"
#include <stdlib.h>

void list_remove_last(list *l) {
    if (l->size == 0) return;
    node *current = l->first;
    node *previous;
    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }
    if (previous->next == NULL) {
        l->first = NULL;
    } else {
        previous->next = NULL;
    }
    free(current);
    l->size--;
}
