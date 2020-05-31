/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_arrlen.c
*/

#include <criterion/criterion.h>

#include "arrayext.h"

Test(arrlen, valid)
{
    char **param1 = malloc(sizeof(char *) * (5));

    param1[0] = "This";
    param1[1] = "is";
    param1[2] = "an";
    param1[3] = "array";
    param1[4] = NULL;

    int actual = 0;
    int expected = 4;

    actual = arrlen((const void **)(param1));
    cr_assert_eq(actual, expected);
}

Test(arrlen, empty)
{
    char **param1 = malloc(sizeof(char *) * (1));

    param1[0] = NULL;

    int actual = 0;
    int expected = 0;

    actual = arrlen((const void **)(param1));
    cr_assert_eq(actual, expected);
}
