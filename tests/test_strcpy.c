#include "common.h"

void test_strcpy_normal(void)
{
    char dest[50];
    char *ret = my_strcpy(dest, "hello");
    TEST_CHECK(ret == dest);
    TEST_CHECK(my_strcmp(dest, "hello") == 0);
}

void test_strcpy_empty(void)
{
    char dest[50];
    char *ret = my_strcpy(dest, "");
    TEST_CHECK(ret == dest);
    TEST_CHECK(my_strcmp(dest, "") == 0);
}

void test_strcpy_long(void)
{
    char dest[100];
    char *ret = my_strcpy(dest, "This is a longer test string.");
    TEST_CHECK(ret == dest);
    TEST_CHECK(my_strcmp(dest, "This is a longer test string.") == 0);
}

void test_strcpy_very_long(void)
{
    char src[1000], dest[1000];
    for (int i = 0; i < 999; i++)
        src[i] = 'A' + (i % 26);
    src[999] = '\0';
    char *ret = my_strcpy(dest, src);
    TEST_CHECK(ret == dest);
    TEST_CHECK(strcmp(dest, src) == 0);
}

void test_strcpy_special(void)
{
    char dest[50];
    char *ret = my_strcpy(dest, "123!@#abc\n\t\r");
    TEST_CHECK(ret == dest);
    TEST_CHECK(my_strcmp(dest, "123!@#abc\n\t\r") == 0);
}

void test_strcpy_destination_null(void)
{
    char *ret = my_strcpy(NULL, "hello");
    TEST_CHECK(ret == NULL);
}

void test_strcpy_source_null(void)
{
    char dest[50];
    char *ret = my_strcpy(dest, NULL);
    TEST_CHECK(ret == NULL);
}

void test_strcpy_both_null(void)
{
    char *ret = my_strcpy(NULL, NULL);
    TEST_CHECK(ret == NULL);
}

TEST_LIST = {
    {"strcpy_normal", test_strcpy_normal},
    {"strcpy_empty", test_strcpy_empty},
    {"strcpy_long", test_strcpy_long},
    {"strcpy_very_long", test_strcpy_very_long},
    {"strcpy_special", test_strcpy_special},
    {"strcpy_dest_null", test_strcpy_destination_null},
    {"strcpy_src_null", test_strcpy_source_null},
    {"strcpy_both_null", test_strcpy_both_null},
    {NULL, NULL}};