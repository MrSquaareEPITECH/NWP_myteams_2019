/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_strsplitj.c
*/

#include <criterion/criterion.h>

#include "stringext.h"

Test(strsplitj, valid)
{
    char *param1 = " This \"is a\" sentence ";
    char *param2 = " ";
    char *param3 = "\"";
    char **actual = NULL;
    char expected[][20] = {
        "This", "\"is a\"", "sentence"
    };

    actual = strsplitj(param1, param2, param3);
    for (int i = 0; i < 3; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(strsplitj, one_word)
{
    char *param1 = " \"One word\" ";
    char *param2 = " ";
    char *param3 = "\"";
    char **actual = NULL;
    char expected[][20] = {
        "\"One word\""
    };

    actual = strsplitj(param1, param2, param3);
    for (int i = 0; i < 1; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(strsplitj, one_word_no_space)
{
    char *param1 = "\"One word\"";
    char *param2 = " ";
    char *param3 = "\"";
    char **actual = NULL;
    char expected[][20] = {
        "\"One word\""
    };

    actual = strsplitj(param1, param2, param3);
    for (int i = 0; i < 1; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(strsplitj, one_word_no_space_no_jump)
{
    char *param1 = "Word";
    char *param2 = " ";
    char *param3 = "\"";
    char **actual = NULL;
    char expected[][20] = {
        "Word"
    };

    actual = strsplitj(param1, param2, param3);
    for (int i = 0; i < 1; ++i)
        cr_assert_str_eq(actual[i], expected[i]);
}

Test(strsplitj, empty)
{
    char *param1 = "";
    char *param2 = " ";
    char *param3 = "\"";
    char **actual = NULL;
    char *expected = NULL;

    actual = strsplitj(param1, param2, param3);
    cr_assert_eq(actual[0], expected);
}
