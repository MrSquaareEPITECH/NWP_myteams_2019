/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strchrn.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strnchr, valid)
{
    char *param1 = " Hello, World! ";
    char param2 = ' ';
    char *actual = NULL;
    char *expected = "Hello, World! ";

    actual = strchrn(param1, param2);
    cr_assert_str_eq(actual, expected);
}

Test(strnchr, not_found)
{
    char *param1 = "AAA";
    char param2 = 'A';
    char *actual = NULL;
    char *expected = NULL;

    actual = strchrn(param1, param2);
    cr_assert_eq(actual, expected);
}
