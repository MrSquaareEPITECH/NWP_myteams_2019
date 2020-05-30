/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strrem.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strrem, valid)
{
    char param1[] = " \tHello, World!\t ";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "Hello,World!";

    actual = strrem(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strrem, empty)
{
    char param1[] = "";
    char *param2 = " \t";
    char *actual = NULL;
    char *expected = "";

    actual = strrem(param1, param2);
    cr_assert_str_eq(actual, expected);
}
