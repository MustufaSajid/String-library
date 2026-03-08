#include "common.h"

void test_strcat_normal(void)
{
    char dest[50] = "Hello, ";
    int ret = my_strcat(dest, "World!", sizeof(dest));
    TEST_CHECK(ret == 0);
    TEST_CHECK(strcmp(dest, "Hello, World!") == 0);
}

void test_strcat_empty_append(void)
{
    char dest[50] = "Hello";
    int ret = my_strcat(dest, "", sizeof(dest));
    TEST_CHECK(ret == 0);
    TEST_CHECK(strcmp(dest, "Hello") == 0);
}

void test_strcat_empty_dest(void)
{
    char dest[50] = "";
    int ret = my_strcat(dest, "Hello", sizeof(dest));
    TEST_CHECK(ret == 0);
    TEST_CHECK(strcmp(dest, "Hello") == 0);
}

void test_strcat_buffer_too_small(void)
{
    char dest[6] = "Hello";
    int ret = my_strcat(dest, "World", sizeof(dest));
    TEST_CHECK(ret == -1);
    TEST_CHECK(dest[5] == '\0');
}

void test_strcat_null_dest(void)
{
    int ret = my_strcat(NULL, "World", 10);
    TEST_CHECK(ret == -2);
}

void test_strcat_null_src(void)
{
    char dest[50] = "Hello";
    int ret = my_strcat(dest, NULL, sizeof(dest));
    TEST_CHECK(ret == -2);
}

TEST_LIST = {
    {"strcat_normal", test_strcat_normal},
    {"strcat_empty_append", test_strcat_empty_append},
    {"strcat_empty_dest", test_strcat_empty_dest},
    {"strcat_buffer_too_small", test_strcat_buffer_too_small},
    {"strcat_null_dest", test_strcat_null_dest},
    {"strcat_null_src", test_strcat_null_src},
    {NULL, NULL}};
