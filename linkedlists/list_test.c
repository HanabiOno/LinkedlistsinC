#include "unity.h"
#include "list.h"

int LENGTH = 42;
list *LIST;

void setUp(void) {
  LIST = make_random_list(LENGTH);
}

void tearDown(void) {
  free_list(LIST);
}

void test_make_list_length(void) {
  TEST_ASSERT_EQUAL_INT(LENGTH, list_length(LIST));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_make_list_length);
    return UNITY_END();
}
