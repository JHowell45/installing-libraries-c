#include "unity.h"
#include "vector.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_vector_get(void)
{
    vector_t *v = newVector(10);
    vector_append(v, 5);
    TEST_ASSERT_EQUAL_INT(vector_get(v, 0), 5);
    freeVector(v);
}

void test_vector_append(void)
{
    const int SIZE = 10;
    vector_t *v = newVector(SIZE / 5);
    for (int i = 0; i < SIZE; i++) {
        vector_append(v, i);
        TEST_ASSERT_EQUAL_INT(vector_get(v, i), i);
    }
    freeVector(v);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_vector_get);
    RUN_TEST(test_vector_append);
    return UNITY_END();
}