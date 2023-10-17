#include "vector.h"
#include <stdlib.h>

vector *vector_add(vector *a, vector *b) {
    vector *res = (vector*)malloc(sizeof(vector));
    res->x = a->x + b->x;
    res->y = a->y + b->y;
    res->z = a->z + b->z;
    return res;
}