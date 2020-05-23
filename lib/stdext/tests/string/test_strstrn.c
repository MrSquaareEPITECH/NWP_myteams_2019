/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strstrn.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strstrn, valid)
{
    char *param1 = " \tHello, World!\t ";
    char *param2 = " \tHello,";
    char *actual = NULL;
    char *expected = " World!\t ";

    actual = strstrn(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strstrn, not_found)
{
    char *param1 = "ABCABCABC";
    char *param2 = "ABC";
    char *actual = NULL;
    char *expected = NULL;

    actual = strstrn(param1, param2);
    cr_assert_eq(actual, expected);
}
