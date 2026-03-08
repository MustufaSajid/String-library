#include "common.h"

void test_equal_strings(void) { TEST_CHECK(my_strcmp("hello", "hello") == 0); }
void test_first_smaller(void) { TEST_CHECK(my_strcmp("apple", "banana") < 0); }
void test_first_larger(void) { TEST_CHECK(my_strcmp("world", "hello") > 0); }
void test_one_shorter(void) { TEST_CHECK(my_strcmp("app", "apple") < 0); }
void test_strcmp_empty_strings(void) { TEST_CHECK(my_strcmp("", "") == 0); }
void test_strcmp_first_empty(void) { TEST_CHECK(my_strcmp("", "hello") < 0); }
void test_strcmp_second_empty(void) { TEST_CHECK(my_strcmp("hello", "") > 0); }
void test_strcmp_case_sensitive(void) { TEST_CHECK(my_strcmp("Hello", "hello") != 0); }
void test_strcmp_special_chars(void)
{
    TEST_CHECK(my_strcmp("!@#$", "!@#$") == 0);
    TEST_CHECK(my_strcmp("!@#$", "!@#%") < 0);
}
void test_strcmp_numbers(void)
{
    TEST_CHECK(my_strcmp("123", "123") == 0);
    TEST_CHECK(my_strcmp("123", "124") < 0);
}
void test_strcmp_mixed_chars(void)
{
    TEST_CHECK(my_strcmp("abc123", "abc123") == 0);
    TEST_CHECK(my_strcmp("abc123", "abc124") < 0);
}

TEST_LIST = {
    {"strcmp_equal", test_equal_strings},
    {"strcmp_first_smaller", test_first_smaller},
    {"strcmp_first_larger", test_first_larger},
    {"strcmp_one_shorter", test_one_shorter},
    {"strcmp_empty_strings", test_strcmp_empty_strings},
    {"strcmp_first_empty", test_strcmp_first_empty},
    {"strcmp_second_empty", test_strcmp_second_empty},
    {"strcmp_case_sensitive", test_strcmp_case_sensitive},
    {"strcmp_special_chars", test_strcmp_special_chars},
    {"strcmp_numbers", test_strcmp_numbers},
    {"strcmp_mixed_chars", test_strcmp_mixed_chars},
    {NULL, NULL}};
