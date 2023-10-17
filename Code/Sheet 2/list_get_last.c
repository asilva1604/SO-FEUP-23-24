#include "list.h"
#include <stdlib.h>


int list_get_last(list *l) {
    node *current = l->first;
    if (l->size == 0) return 0;
    while (current->next != NULL) {
        current = current->next;
    }
    return current->val;
}
