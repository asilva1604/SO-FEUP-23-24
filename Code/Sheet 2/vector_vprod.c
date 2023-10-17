#include "vector.h"
#include <stdlib.h>

vector *vector_vprod(vector *a, vector *b) {
    vector *res = (vector*)malloc(sizeof(vector));
    res->x = a->y * b->z - a->z * b->y;
    res->y = a->x * b->x - a->z * b->x;
    res->z = a->x * b->y - a->y * b->x;
    return res;
}