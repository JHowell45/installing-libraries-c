#include "vector.h"

vector_t *newVector(size_t capacity)
{
    vector_t *vec = malloc(sizeof(vector_t));
    vec->capacity = capacity;
    vec->size = 0;
    vec->items = NULL;
}
void freeVector(vector_t *vec)
{
    if (vec->items != NULL) {
        free(vec->items);
    }
    free(vec);
}

void vector_append(vector_t *vec, void *item)
{
    if (vec->items == NULL) {
        vec->items = calloc(vec->capacity, sizeof(item));
    }
}
void vector_pop(vector_t *vec)
{
}
void vector_insert(vector_t *vec, void *item, size_t index)
{
}
void vector_remove(vector_t *vec, size_t index)
{
}

void *vector_get(vector_t *vec, size_t index)
{
    return vec->items[index];
}