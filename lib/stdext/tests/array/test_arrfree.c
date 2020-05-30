/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** test_arrfree.c
*/

#include <criterion/criterion.h>

#include "arrayext.h"

Test(arrfree, valid)
{
    char **param1 = malloc(sizeof(char *) * (5));

    param1[0] = strdup("This");
    param1[1] = strdup("is");
    param1[2] = strdup("an");
    param1[3] = strdup("array");
    param1[4] = NULL;

    arrfree((void **)(param1), free);
}

Test(arrfree, empty)
{
    char **param1 = malloc(sizeof(char *) * (1));

    param1[0] = NULL;

    arrfree((void **)(param1), free);
}
