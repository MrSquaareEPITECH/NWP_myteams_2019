/*
** EPITECH PROJECT, 2020
** server
** File description:
** command_util.c
*/

#include "command_util.h"

#include "def/data.h"
#include "util/string.h"

char *command_to_data(const command_t *command)
{
    char *data = strfmt(DATA_COMMAND, command->name, command->help);

    return (data);
}
