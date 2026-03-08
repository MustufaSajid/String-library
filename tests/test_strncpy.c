#include "common.h"

void test_strncpy_normal(void)
{
    char dest[10];
    my_strncpy(dest, "Hello", 5, sizeof(dest));
    TEST_CHECK(strcmp(dest, "Hello") == 0);
}

void test_strncpy_padding(void)
{
    char dest[10];
    my_strncpy(dest, "Hi", 5, sizeof(dest));
    for (int i = 2; i < 5; i++)
        TEST_CHECK(dest[i] == '\0');
}

void test_strncpy_long_source(void)
{
    char dest[5];
    my_strncpy(dest, "HelloWorld", 5, sizeof(dest));
    TEST_CHECK(dest[4] == '\0');
    TEST_CHECK(strncmp(dest, "Hell", 4) == 0);
}

void test_strncpy_zero_n(void)
{
    char dest[5] = "AAAA";
    my_strncpy(dest, "Hi", 0, sizeof(dest));
    TEST_CHECK(strcmp(dest, "AAAA") == 0);
}

void test_strncpy_small_buffer(void)
{
    char dest[3];
    my_strncpy(dest, "Hello", 5, sizeof(dest));
    TEST_CHECK(dest[2] == '\0');
}

void test_strncpy_null_dest(void)
{
    char *ret = my_strncpy(NULL, "Hello", 5, 10);
    TEST_CHECK(ret == NULL);
}

void test_strncpy_null_src(void)
{
    char dest[10];
    char *ret = my_strncpy(dest, NULL, 5, sizeof(dest));
    TEST_CHECK(ret == NULL);
}

TEST_LIST = {
    {"strncpy_normal", test_strncpy_normal},
    {"strncpy_padding", test_strncpy_padding},
    {"strncpy_long_source", test_strncpy_long_source},
    {"strncpy_zero_n", test_strncpy_zero_n},
    {"strncpy_small_buffer", test_strncpy_small_buffer},
    {"strncpy_null_dest", test_strncpy_null_dest},
    {"strncpy_null_src", test_strncpy_null_src},
    {NULL, NULL}};
