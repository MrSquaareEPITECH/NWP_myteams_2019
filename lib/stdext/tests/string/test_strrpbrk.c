/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strrpbrk.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strrpbrk, valid)
{
    char *param1 = " \tHello, World!\t ";
    char *param2 = ",!";
    char *actual = NULL;
    char *expected = "!\t ";

    actual = strrpbrk(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strrpbrk, not_found)
{
    char *param1 = "ABCABCABC";
    char *param2 = "DEF";
    char *actual = NULL;
    char *expected = NULL;

    actual = strrpbrk(param1, param2);
    cr_assert_eq(actual, expected);
}
