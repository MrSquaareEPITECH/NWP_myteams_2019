/*
** EPITECH PROJECT, 2020
** server
** File description:
** use_server.c
*/

#include "command/use_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "util/string.h"

static int reply(client_t *client)
{
    char *response = strfmt(RESPONSE_SERVER_USE_OK, "Success");

    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int use_server(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);
    (void)(argc);

    client->user->use = USE_SERVER;
    client->user->obj = NULL;
    if (reply(client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
