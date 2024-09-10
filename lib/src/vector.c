#include <stdio.h>

#include "vector.h"

vector_t *newVector(size_t capacity)
{
    vector_t *vec = malloc(sizeof(vector_t));
    vec->capacity = capacity;
    vec->size = 0;
    vec->items = calloc(vec->capacity, sizeof(int));
    return vec;
}
void freeVector(vector_t *vec)
{
    if (vec->items != NULL) {
        free(vec->items);
    }
    free(vec);
}

void printVector(vector_t *vec)
{
    printf("[");
    for (int i = 0; i < vec->size; i++) {
        int value = vector_get(vec, i);
        if (i == 0) {
            printf("%d", value);
        } else {
            printf(", %d", value);
        }
    }
    printf("]\n");
}

void vector_append(vector_t *vec, int item)
{
    // if (vec->items == NULL) {
    //     vec->items = calloc(vec->capacity, sizeof(int));
    // }
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->items = realloc(vec->items, vec->capacity * sizeof(int));
    }
    vec->items[vec->size] = item;
    vec->size++;
}
void vector_pop(vector_t *vec)
{
    if (vec->size > 0) {
        vec->size--;
    }
}
void vector_insert(vector_t *vec, int item, size_t index)
{
}
void vector_remove(vector_t *vec, size_t index)
{
}

int vector_get(vector_t *vec, size_t index)
{
    return vec->items[index];
}