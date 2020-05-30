/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strsplit.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strsplit, valid)
{
    char *param1 = " This \"is a\" sentence ";
    char *param2 = " ";
    char **actual = NULL;
    char expected[][20] = {
        "This", "\"is", "a\"", "sentence"
    };

    actual = strsplit(param1, param2);
    for (int i = 0; i < 4; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(strsplit, one_word)
{
    char *param1 = " Word ";
    char *param2 = " ";
    char **actual = NULL;
    char expected[][20] = {
        "Word"
    };

    actual = strsplit(param1, param2);
    for (int i = 0; i < 1; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(strsplit, one_word_no_space)
{
    char *param1 = "Word";
    char *param2 = " ";
    char **actual = NULL;
    char expected[][20] = {
        "Word"
    };

    actual = strsplit(param1, param2);
    for (int i = 0; i < 1; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(strsplit, empty)
{
    char *param1 = "";
    char *param2 = " ";
    char **actual = NULL;
    char *expected = NULL;

    actual = strsplit(param1, param2);
    cr_assert_eq(actual[0], expected);
}
