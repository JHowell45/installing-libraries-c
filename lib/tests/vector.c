#include "unity.h"
#include "vector.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_get_key(void)
{
    vector_t *v = newVector(10);
    // TEST_ASSERT_EQUAL_INT(v->key, 10);
    freeVector(v);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_get_key);
    return UNITY_END();
}