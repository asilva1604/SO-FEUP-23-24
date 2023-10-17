#include "list.h"
#include <stdio.h>

void list_print(list* l) {
    printf("[");
    node *current = l->first;
    while (current->next != NULL) {
        printf("%d, ", current->val);
    }
    printf("%d]\n", current->val);
}