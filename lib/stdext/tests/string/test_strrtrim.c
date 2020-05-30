/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strrtrim.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strrtrim, valid)
{
    char *param1 = " \tHello, World!\t ";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = " \tHello, World!";

    actual = strrtrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strrtrim, useless)
{
    char *param1 = " \tHello, World!";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = " \tHello, World!";

    actual = strrtrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strrtrim, empty)
{
    char *param1 = "";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "";

    actual = strrtrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}
