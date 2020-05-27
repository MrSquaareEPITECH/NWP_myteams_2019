/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** command.c
*/

#include "command.h"

#include <string.h>

const command_t *command_get(const char *name)
{
    for (size_t i = 0; COMMANDS[i].name; ++i)
        if (strcmp(COMMANDS[i].name, name) == 0)
            return (&COMMANDS[i]);
    return (NULL);
}
