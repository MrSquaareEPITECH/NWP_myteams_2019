/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_arrdup.c
*/

#include <criterion/criterion.h>

#include "arrayext.h"

Test(arrdup, valid)
{
    char **param1 = malloc(sizeof(char *) * (5));

    param1[0] = "This";
    param1[1] = "is";
    param1[2] = "an";
    param1[3] = "array";
    param1[4] = NULL;

    char **actual = NULL;
    char expected[][20] = {
        "This", "is", "an", "array"
    };

    actual = (char **)(arrdup((const void **)(param1), (duplicate_t)(strdup)));
    for (int i = 0; i < 4; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(arrdup, empty)
{
    char **param1 = malloc(sizeof(char *) * (1));

    param1[0] = NULL;

    char **actual = NULL;
    char *expected = NULL;

    actual = (char **)(arrdup((const void **)(param1), (duplicate_t)(strdup)));
    cr_assert_eq(actual[0], expected);
}
