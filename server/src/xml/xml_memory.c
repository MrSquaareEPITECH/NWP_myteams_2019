/*
** EPITECH PROJECT, 2020
** server
** File description:
** xml_memory.c
*/

#include "xml_memory.h"

#include "xml_internal.h"

char *xml_from_memory(const char *str)
{
    char *format = xml_format(str);

    return (format);
}
