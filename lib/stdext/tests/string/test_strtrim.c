/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strtrim.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strtrim, valid)
{
    char *param1 = " \tHello, World!\t ";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "Hello, World!";

    actual = strtrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strtrim, useless)
{
    char *param1 = "Hello, World!";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "Hello, World!";

    actual = strtrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strtrim, empty)
{
    char *param1 = "";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "";

    actual = strtrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}
