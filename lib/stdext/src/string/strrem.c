/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strrem.c
*/

#include "stringext.h"

#include <string.h>

char *strrem(char *str, const char *list)
{
    size_t j = 0;

    for (size_t i = 0, len = strlen(str); i < len; i++)
        if (strchr(list, str[i]) == NULL)
            str[j++] = str[i];
    str[j] = '\0';
    return (str);
}
