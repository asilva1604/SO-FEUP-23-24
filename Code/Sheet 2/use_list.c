#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv) {
    list *l1 = list_new();
    list *l2 = list_new_random(4, 10);
    list_add_first(3, l1);
    list_add_last(6, l1);
    list_print(l1);
    printf("%d\n", list_get_first(l1));
    printf("%d\n", list_get_last(l1));
    list_print(l2);
    list_remove_first(l2);
    list_print(l2);
    list_remove_last(l2);
    list_print(l2);
    printf("%d", list_size(l2));
    return 0;
}