/*
** EPITECH PROJECT, 2020
** server
** File description:
** logout.c
*/

#define _GNU_SOURCE

#include "logout.h"

#include <stdio.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/data.h"
#include "def/event.h"
#include "def/response.h"
#include "server/server_util.h"
#include "user/user.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_USER_LOGOUT_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, user_t *user)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_USER_LOGOUT_OK, "Success");
    asprintf(&data, DATA_USER, user->uuid, user->name);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, user_t *user)
{
    char *data = NULL;

    asprintf(&data, DATA_USER, user->uuid, user->name);
    if (server_broadcast(server, EVENT_USER_LOGGEDOUT, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int logout_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *user = client->user;

    if (reply(client, user) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, user) == CODE_ERROR)
        return (CODE_ERROR);
    list_remove(server->users, user);
    client->state = CLIENT_CONNECTED;
    client->user = NULL;
    user_delete(user);
    return (CODE_SUCCESS);
}
