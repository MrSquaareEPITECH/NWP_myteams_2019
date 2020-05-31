/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strrev.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strrev, valid)
{
    char param1[] = "Hello, World!";
    char *actual = NULL;
    char *expected = "!dlroW ,olleH";

    actual = strrev(param1);
    cr_assert_str_eq(actual, expected);
}

Test(strrev, empty)
{
    char param1[] = "";
    char *actual = NULL;
    char *expected = "";

    actual = strrev(param1);
    cr_assert_str_eq(actual, expected);
}
