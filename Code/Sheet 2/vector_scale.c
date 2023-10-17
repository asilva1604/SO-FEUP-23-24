#include "vector.h"
#include <stdlib.h>

vector *vector_scale(double a, vector *v) {
    vector *new = (vector*)malloc(sizeof(vector));
    new->x = v->x * a;
    new->y = v->y * a;
    new->z = v->z * a;
    return new;
}