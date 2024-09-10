#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    int *items;
    size_t capacity;
    size_t size;
} vector_t;

vector_t *newVector(size_t capacity);
void freeVector(vector_t *vec);
void printVector(vector_t *vec);

void vector_append(vector_t *vec, int item);
void vector_pop(vector_t *vec);
void vector_insert(vector_t *vec, int item, size_t index);
void vector_remove(vector_t *vec, size_t index);

int vector_get(vector_t *vec, size_t index);

#endif