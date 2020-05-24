/*
** EPITECH PROJECT, 2020
** server
** File description:
** help.c
*/

#define _GNU_SOURCE

#include "help.h"

#include <stdio.h>
#include <string.h>

#include "def/code.h"
#include "def/command.h"
#include "def/data.h"
#include "def/response.h"

static int reply(client_t *client)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_GLOBAL_HELP_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_GLOBAL_HELP_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (int i = 0; COMMANDS[i].name; ++i) {
        char *data = NULL;

        asprintf(&data, DATA_COMMAND, COMMANDS[i].name, COMMANDS[i].help);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_GLOBAL_HELP_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int help_command(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    reply(client);
    return (CODE_SUCCESS);
}
