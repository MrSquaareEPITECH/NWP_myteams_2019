/*
** EPITECH PROJECT, 2020
** server
** File description:
** help.c
*/

#include "help.h"

#include <string.h>

#include "command_util.h"
#include "def/code.h"
#include "def/command.h"
#include "def/response.h"
#include "util/string.h"

static int reply(client_t *client)
{
    char *response = strfmt(RESPONSE_GLOBAL_HELP_OK, "Success");
    const char *start = RESPONSE_GLOBAL_HELP_START;
    const char *end = RESPONSE_GLOBAL_HELP_END;

    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(start)) == CODE_ERROR)
        return (CODE_ERROR);
    for (int i = 0; COMMANDS[i].name; ++i) {
        char *data = command_to_data(&COMMANDS[i]);

        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(end)) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int help_command(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    if (reply(client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
