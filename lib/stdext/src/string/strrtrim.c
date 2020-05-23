/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strrtrim.c
*/

#include <string.h>

#include "stringext.h"

char *strrtrim(const char *str, const char *list)
{
    char *ptr = strrpbrkn(str, list);

    if (ptr == NULL)
        return (strdup(str));

    char *rtrim = strndup(str, ptr - str + 1);

    return (rtrim);
}
