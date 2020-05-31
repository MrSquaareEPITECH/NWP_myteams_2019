/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strsplitj.c
*/

#include <stdlib.h>
#include <string.h>

#include "stringext.h"

static size_t strsplitj_size(
    const char *str, const char *delim, const char *jump)
{
    size_t size = 0;
    char *ptr = (char *)(str);

    while (ptr && *ptr) {
        ptr = strstrn(ptr, delim);
        if (ptr && (strncmp(ptr, jump, strlen(jump)) == 0)) {
            ptr = strstr(ptr + 1, jump);
            ptr += (ptr) ? 1 : 0;
        } else if (ptr && (strncmp(ptr, delim, strlen(delim)) != 0))
            ptr = strstr(ptr, delim);
        if (ptr)
            ptr = strstrn(ptr, delim);
        size++;
    }
    return (size);
}

char **strsplitj(const char *str, const char *delim, const char *jump)
{
    size_t size = strsplitj_size(str, delim, jump);
    char **splitj = malloc(sizeof(char *) * (size + 1));
    char *from = NULL;
    char *to = NULL;
    int i = 0;

    for (char *ptr = strstrn(str, delim); ptr && *ptr;
        ptr = (ptr) ? strstrn(ptr, delim) : NULL) {
        from = ptr;
        if (strncmp(ptr, jump, strlen(jump)) == 0) {
            ptr = strstr(ptr + 1, jump);
            ptr += (ptr) ? 1 : 0;
        } else if (strncmp(ptr, delim, strlen(delim)) != 0)
            ptr = strstr(ptr, delim);
        to = ptr;
        splitj[i++] = strndup(from, to - from);
    }
    splitj[size] = NULL;
    return (splitj);
}
