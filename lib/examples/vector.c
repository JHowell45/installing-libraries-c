#include "vector.h"

int main(void)
{
    vector_t *v = newVector(5);
    freeVector(v);

    return 0;
}