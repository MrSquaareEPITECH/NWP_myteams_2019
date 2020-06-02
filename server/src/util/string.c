/*
** EPITECH PROJECT, 2020
** server
** File description:
** message.c
*/

#include "string.h"

#include <stdarg.h>
#include <stdio.h>

char *strfmt(const char *fmt, ...)
{
    char *str = NULL;
    va_list args;

    va_start(args, fmt);
    vasprintf(&str, fmt, args);
    va_end(args);

    return (str);
}
