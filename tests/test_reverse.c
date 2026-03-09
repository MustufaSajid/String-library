#include "common.h"

void test_reverse_null(void)
{
    int ret = my_strrev(NULL);
    TEST_CHECK(ret == -1);
}

void test_reverse_empty(void)
{
    char str[] = "";
    int ret = my_strrev(str);
    TEST_CHECK(ret == 0);
    TEST_CHECK(my_strcmp(str, "") == 0);
}

void test_reverse_single(void)
{
    char str[] = "A";
    int ret = my_strrev(str);
    TEST_CHECK(ret == 0);
    TEST_CHECK(my_strcmp(str, "A") == 0);
}

void test_reverse_normal(void)
{
    char str[] = "Hello";
    int ret = my_strrev(str);
    TEST_CHECK(ret == 0);
    TEST_CHECK(my_strcmp(str, "olleH") == 0);
}

void test_reverse_complex(void)
{
    char str[] = "A B!C";
    int ret = my_strrev(str);
    TEST_CHECK(ret == 0);
    TEST_CHECK(my_strcmp(str, "C!B A") == 0);
}

TEST_LIST = {
    {"reverse_null", test_reverse_null},
    {"reverse_empty", test_reverse_empty},
    {"reverse_single", test_reverse_single},
    {"reverse_normal", test_reverse_normal},
    {"reverse_complex", test_reverse_complex},
    {NULL, NULL}};