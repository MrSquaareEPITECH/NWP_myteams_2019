/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strsplit.c
*/

#include <stdlib.h>
#include <string.h>

#include "stringext.h"

static size_t strsplit_size(const char *str, const char *delim)
{
    size_t size = 0;
    char *ptr = (char *)(str);

    while (ptr && *ptr) {
        ptr = strstrn(ptr, delim);
        if (ptr && (strncmp(ptr, delim, strlen(delim)) != 0))
            ptr = strstr(ptr, delim);
        if (ptr)
            ptr = strstrn(ptr, delim);
        size++;
    }

    return (size);
}

char **strsplit(const char *str, const char *delim)
{
    size_t size = strsplit_size(str, delim);
    char **split = malloc(sizeof(char *) * (size + 1));
    char *from = NULL;
    char *to = NULL;
    int i = 0;

    for (char *ptr = strstrn(str, delim); ptr && *ptr;
        ptr = (ptr) ? strstrn(ptr, delim) : NULL) {
        from = ptr;
        if (strncmp(ptr, delim, strlen(delim)) != 0)
            ptr = strstr(ptr, delim);
        to = ptr;
        split[i++] = strndup(from, to - from);
    }
    split[size] = NULL;
    return (split);
}
