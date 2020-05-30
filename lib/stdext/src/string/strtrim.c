/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strtrim.c
*/

#include <stdlib.h>

#include "stringext.h"

char *strtrim(const char *str, const char *list)
{
    char *ltrim = strltrim(str, list);
    char *trim = strrtrim(ltrim, list);

    free(ltrim);
    return (trim);
}
