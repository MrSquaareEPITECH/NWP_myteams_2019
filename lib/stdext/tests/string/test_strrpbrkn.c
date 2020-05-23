/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strrpbrkn.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strrpbrkn, valid)
{
    char *param1 = " \tHello, World!\t ";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "!\t ";

    actual = strrpbrkn(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strrpbrkn, not_found)
{
    char *param1 = "ABCABCABC";
    char *param2 = "ABC";
    char *actual = NULL;
    char *expected = NULL;

    actual = strpbrkn(param1, param2);
    cr_assert_eq(actual, expected);
}
