/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strrstr.c
*/

#include <stdlib.h>
#include <string.h>

#include "stringext.h"

char *strrstr(const char *str, const char *needle)
{
    char *rev = strrev(strdup(str));
    char *rev_needle = strrev(strdup(needle));
    char *ptr = strstr(rev, rev_needle);

    if (ptr == NULL)
        return (NULL);

    size_t pos = strlen(str) - (ptr - rev) - strlen(needle);

    free(rev_needle);
    free(rev);
    return ((char *)(&str[pos]));
}
