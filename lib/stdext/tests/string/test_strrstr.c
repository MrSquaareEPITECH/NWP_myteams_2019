/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strrstr.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strrstr, valid)
{
    char *param1 = " \tHello, World!\t ";
    char *param2 = "World!";
    char *actual = NULL;
    char *expected = "World!\t ";

    actual = strrstr(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strrstr, not_found)
{
    char *param1 = "ABCABCABC";
    char *param2 = "DEF";
    char *actual = NULL;
    char *expected = NULL;

    actual = strrstr(param1, param2);
    cr_assert_eq(actual, expected);
}
