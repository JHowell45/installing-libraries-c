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
    printf("Vector {\n");
    printf("\tSize: %zu\n", vec->size);
    printf("\tCapacity: %zu\n", vec->capacity);
    printf("\tItems: [");
    for (int i = 0; i < vec->size; i++) {
        int value = vector_get(vec, i);
        if (i == 0) {
            printf("%d", value);
        } else {
            printf(", %d", value);
        }
    }
    printf("]\n");
    printf("}\n");
}

void static resize_internal(vector_t *vec)
{
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->items = realloc(vec->items, vec->capacity * sizeof(int));
    }
}

void vector_append(vector_t *vec, int item)
{
    resize_internal(vec);
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
    resize_internal(vec);
    for (int i = vec->size - 1; i >= index; i--) {
        vec->items[i + 1] = vec->items[i];
    }
    vec->items[index] = item;
    vec->size++;
}
void vector_remove(vector_t *vec, size_t index)
{
    for (int i = index; i < vec->size; i++) {
        vec->items[i] = vec->items[i + 1];
    }
    vec->size--;
}

int vector_get(vector_t *vec, size_t index)
{
    return vec->items[index];
}