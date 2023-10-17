#include "vector.h"


double vector_sprod(vector* vec1, vector* vec2) {
    return (vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z);
}