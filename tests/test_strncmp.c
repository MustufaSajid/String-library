#include "common.h"

void test_strncmp_equal(void) { TEST_CHECK(my_strncmp("cat", "cat", 3) == 0); }
void test_strncmp_diff_inside_limit(void) { TEST_CHECK(my_strncmp("cat", "car", 3) != 0); }
void test_strncmp_diff_outside_limit(void) { TEST_CHECK(my_strncmp("cat", "car", 2) == 0); }
void test_strncmp_zero_n(void) { TEST_CHECK(my_strncmp("cat", "dog", 0) == 0); }
void test_strncmp_first_shorter(void) { TEST_CHECK(my_strncmp("cat", "catapult", 100) < 0); }
void test_strncmp_second_shorter(void) { TEST_CHECK(my_strncmp("catapult", "cat", 100) > 0); }
void test_strncmp_empty_strings(void) { TEST_CHECK(my_strncmp("", "", 5) == 0); }
void test_strncmp_first_empty(void) { TEST_CHECK(my_strncmp("", "hello", 5) < 0); }
void test_strncmp_second_empty(void) { TEST_CHECK(my_strncmp("hello", "", 5) > 0); }

TEST_LIST = {
    {"strncmp_equal", test_strncmp_equal},
    {"strncmp_diff_inside", test_strncmp_diff_inside_limit},
    {"strncmp_diff_outside", test_strncmp_diff_outside_limit},
    {"strncmp_zero_n", test_strncmp_zero_n},
    {"strncmp_first_shorter", test_strncmp_first_shorter},
    {"strncmp_second_shorter", test_strncmp_second_shorter},
    {"strncmp_empty_both", test_strncmp_empty_strings},
    {"strncmp_first_empty", test_strncmp_first_empty},
    {"strncmp_second_empty", test_strncmp_second_empty},
    {NULL, NULL}};
