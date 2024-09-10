#include <stdio.h>

#include "vector.h"

#define MAX_VALUES 10

int main(void)
{
    vector_t *v = newVector(2);
    printVector(v);
    for (int i = 0; i < MAX_VALUES; i++) {
        vector_append(v, i);
        printVector(v);
    }

    vector_insert(v, 100, 2);
    printVector(v);

    for (int i = 0; i < MAX_VALUES / 2; i++) {
        vector_remove(v, 0);
        printVector(v);
    }

    freeVector(v);
    return 0;
}