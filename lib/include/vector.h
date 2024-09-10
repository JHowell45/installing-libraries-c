#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

typedef struct {
    void **items;
    size_t capacity;
    size_t size;
} vector_t;

#endif