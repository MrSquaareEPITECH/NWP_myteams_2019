/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strstrn.c
*/

#include <string.h>

#include "stringext.h"

char *strstrn(const char *str, const char *needle)
{
    char *npos = (char *)(str);

    for (char *ptr = strstr(str, needle); (npos) && (npos == ptr);
    npos = ptr + strlen(needle), ptr = strstr(npos, needle)) ;
    if (*npos == '\0')
        return (NULL);
    return (npos);
}
