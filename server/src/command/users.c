/*
** EPITECH PROJECT, 2020
** server
** File description:
** users.c
*/

#define _GNU_SOURCE

#include "users.h"

#include <stdio.h>
#include <string.h>

#include "def/code.h"
#include "def/data.h"
#include "def/response.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_USER_LIST_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, server_t *server)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_USER_LIST_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_USER_LIST_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = server->users->begin; node; node = node->next) {
        char *data = NULL;
        user_t *user = (user_t *)(node->obj);

        asprintf(&data, DATA_USER, user->uuid, user->name);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_USER_LIST_END)) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int users_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);
    reply(client, server);
    return (CODE_SUCCESS);
}
