#include "vector.h"
#include <stdlib.h>

vector *vector_new(double a, double b, double c) {
    vector *v = (vector*)malloc(sizeof(vector));
    v->x = a;
    v->y = b;
    v->z = c;
    return v;
}