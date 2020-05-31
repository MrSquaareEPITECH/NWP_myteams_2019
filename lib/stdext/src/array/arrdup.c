/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** arrdup.c
*/

#include "arrayext.h"

#include <stdlib.h>

void **arrdup(const void **arr, duplicate_t duplicate)
{
    size_t len = arrlen(arr);
    void **dup = malloc(sizeof(void *) * (len + 1));

    for (size_t i = 0; i < len; ++i)
        dup[i] = duplicate(arr[i]);
    dup[len] = NULL;
    return (dup);
}
