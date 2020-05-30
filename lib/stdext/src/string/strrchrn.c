/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strrchrn.c
*/

#include <stdlib.h>
#include <string.h>

#include "stringext.h"

char *strrchrn(const char *str, char chr)
{
    char *rev = strrev(strdup(str));
    char *ptr = strchrn(rev, chr);

    if (ptr == NULL)
        return (NULL);

    size_t pos = strlen(str) - (ptr - rev) - 1;

    free(rev);
    return ((char *)(&str[pos]));
}
