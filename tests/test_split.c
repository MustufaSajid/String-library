#include "common.h"

void test_basic_split(void)
{
    char **r = my_split("a,b,c", ',');
    TEST_CHECK(strcmp(r[0], "a") == 0);
    TEST_CHECK(strcmp(r[1], "b") == 0);
    TEST_CHECK(strcmp(r[2], "c") == 0);
    TEST_CHECK(r[3] == NULL);
    free_split(&r);
}

void test_single_word(void)
{
    char **r = my_split("hello", ',');
    TEST_CHECK(strcmp(r[0], "hello") == 0);
    TEST_CHECK(r[1] == NULL);
    free_split(&r);
}

void test_empty_string(void)
{
    char **r = my_split("", ',');
    TEST_CHECK(r[0] == NULL);
    free_split(&r);
}

void test_only_delimiters(void)
{
    char **r = my_split(",,,", ',');
    TEST_CHECK(r[0] == NULL);
    free_split(&r);
}

void test_multiple_delimiters(void)
{
    char **r = my_split("a,,b,,,c", ',');
    TEST_CHECK(strcmp(r[0], "a") == 0);
    TEST_CHECK(strcmp(r[1], "b") == 0);
    TEST_CHECK(strcmp(r[2], "c") == 0);
    TEST_CHECK(r[3] == NULL);
    free_split(&r);
}

void test_leading_trailing(void)
{
    char **r1 = my_split(",a,b", ',');
    TEST_CHECK(strcmp(r1[0], "a") == 0);
    TEST_CHECK(strcmp(r1[1], "b") == 0);
    TEST_CHECK(r1[2] == NULL);
    free_split(&r1);

    char **r2 = my_split("a,b,", ',');
    TEST_CHECK(strcmp(r2[0], "a") == 0);
    TEST_CHECK(strcmp(r2[1], "b") == 0);
    TEST_CHECK(r2[2] == NULL);
    free_split(&r2);
}

void test_spaces(void)
{
    char **r = my_split("one two three", ' ');
    TEST_CHECK(strcmp(r[0], "one") == 0);
    TEST_CHECK(strcmp(r[1], "two") == 0);
    TEST_CHECK(strcmp(r[2], "three") == 0);
    TEST_CHECK(r[3] == NULL);
    free_split(&r);
}

TEST_LIST = {
    {"basic_split", test_basic_split},
    {"single_word", test_single_word},
    {"empty_string", test_empty_string},
    {"only_delimiters", test_only_delimiters},
    {"multiple_delimiters", test_multiple_delimiters},
    {"leading_trailing", test_leading_trailing},
    {"spaces", test_spaces},
    {NULL, NULL}};
