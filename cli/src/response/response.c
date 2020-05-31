/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.c
*/

#include "response.h"

#include <string.h>

const response_t *response_get(const char *name)
{
    for (size_t i = 0; RESPONSES[i].name; ++i)
        if (strcmp(RESPONSES[i].name, name) == 0)
            return (&RESPONSES[i]);
    return (NULL);
}
