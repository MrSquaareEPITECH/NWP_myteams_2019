/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** arrfree.c
*/

#include <stdlib.h>

#include "arrayext.h"

void arrfree(void **arr, delete_t delete)
{
    size_t len = arrlen((const void **)(arr));

    for (size_t i = 0; i < len; ++i)
        delete(arr[i]);
    free(arr);
}
