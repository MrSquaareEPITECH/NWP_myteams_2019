/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strchrn.c
*/

#include <stddef.h>
#include <string.h>

#include "stringext.h"

char *strchrn(const char *str, char chr)
{
    for (size_t i = 0, len = strlen(str); i < len; ++i)
        if (str[i] != chr)
            return ((char *)(&str[i]));
    return (NULL);
}
