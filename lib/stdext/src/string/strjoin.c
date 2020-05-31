/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strjoin.c
*/

#include <stdlib.h>
#include <string.h>

#include "arrayext.h"
#include "stringext.h"

char *strjoin(const char **arr, const char *delim)
{
    char *str = NULL;
    size_t len = 0;

    for (size_t i = 0; arr[i]; ++i) {
        if (i)
            len += strlen(delim);
        len += strlen(arr[i]);
    }
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    memset(str, 0, len + 1);
    for (size_t i = 0; arr[i]; ++i) {
        if (i)
            str = strcat(str, delim);
        str = strcat(str, arr[i]);
    }
    return (str);
}
