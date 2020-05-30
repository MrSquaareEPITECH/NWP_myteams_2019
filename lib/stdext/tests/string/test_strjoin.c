/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strjoin.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strjoin, valid)
{
    char **param1 = strsplit("This is a test", " ");
    char *param2 = "-";
    char *actual = NULL;
    char *expected = "This-is-a-test";

    actual = strjoin((const char **)(param1), param2);
    cr_assert_str_eq(actual, expected);
}

Test(strjoin, empty)
{
    char **param1 = strsplit("", " ");
    char *param2 = "-";
    char *actual = NULL;
    char *expected = "";

    actual = strjoin((const char **)(param1), param2);
    cr_assert_str_eq(actual, expected);
}
