/*
** EPITECH PROJECT, 2020
** server
** File description:
** xml_internal.c
*/

#include "xml_internal.h"

#include <arrayext.h>
#include <stdlib.h>
#include <stringext.h>

#include "pcre/pcre.h"

char *xml_format(const char *str)
{
    char *format = NULL;
    char **arr = strsplit(str, "\n");
    size_t len = arrlen((const void **)(arr));
    char **trim_arr = malloc(sizeof(char *) * (len + 1));

    for (size_t i = 0; arr[i]; ++i)
        trim_arr[i] = strtrim(arr[i], " \t");
    trim_arr[len] = NULL;
    format = strjoin((const char **)(trim_arr), "");
    arrfree((void **)(trim_arr), free);
    arrfree((void **)(arr), free);
    return (format);
}
