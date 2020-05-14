/*
** EPITECH PROJECT, 2020
** server
** File description:
** string.c
*/

#include "string.h"

#include <stdlib.h>
#include <string.h>

static int strsplit_count(const char *str, char *delim)
{
    int count = 0;
    char *dup = strdup(str);

    for (char *token = strtok(dup, delim); token;
         token = strtok(NULL, delim), ++count)
        ;

    free(dup);

    return (count);
}

char **strsplit(const char *str, char *delim)
{
    int size = strsplit_count(str, delim);
    char *dup = strdup(str);
    char **split = malloc(sizeof(char *) * (size + 1));
    char *token = strtok(dup, delim);

    for (int i = 0; i < size; token = strtok(NULL, delim), ++i)
        split[i] = strdup(token);

    split[size] = NULL;

    free(dup);

    return (split);
}
