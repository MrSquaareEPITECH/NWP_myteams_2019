/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_memdup.c
*/

#include <criterion/criterion.h>

#include "memoryext.h"

Test(memdup, valid)
{
    char *param1 = "Hello, World!";
    char *actual = NULL;
    char *expected = "Hello, World!";

    actual = memdup(param1, strlen(param1) + 1);
    cr_assert_str_eq(actual, expected);
}

Test(memdup, zero)
{
    char *param1 = NULL;

    memdup(param1, 0);
}
