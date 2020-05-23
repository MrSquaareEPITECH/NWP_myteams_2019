/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strltrim.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strltrim, valid)
{
    char *param1 = " \tHello, World!\t ";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "Hello, World!\t ";

    actual = strltrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strltrim, useless)
{
    char *param1 = "Hello, World!\t ";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "Hello, World!\t ";

    actual = strltrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strltrim, empty)
{
    char *param1 = "";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "";

    actual = strltrim(param1, param2);
    cr_assert_str_eq(actual, expected);
}
