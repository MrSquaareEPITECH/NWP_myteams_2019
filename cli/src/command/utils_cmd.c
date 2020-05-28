/*
** EPITECH PROJECT, 2019
** Visual Studio Live Share (Workspace)
** File description:
** utils_cmd.c
*/

#include "my.h"

char *check_status(char *word)
{
    char *status = NULL;

    if (strcasecmp(word, "OK") == 0) {
        status = malloc(sizeof(char) * 8);
        if (status == NULL)
            return (NULL);
        strcpy(status, "Success");
    } else {
        status = malloc(sizeof(char) * 6);
        if (status == NULL)
            return (NULL);
        strcpy(status, "Error");
    }
    return (status);
}