/*
** EPITECH PROJECT, 2020
** server
** File description:
** user.c
*/

#define _GNU_SOURCE

#include "user.h"

#include <stdio.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "get_error_util.h"
#include "user/user.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_USER_INFO_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        asprintf(&error, RESPONSE_USER_INFO_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, user_t *user)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_USER_INFO_OK, "Success");
    asprintf(&data, DATA_USER, user->uuid, user->name);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int user_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *user =
        get_error_user(client, RESPONSE_USER_INFO_KO, server, argv[1]);

    if (user == NULL)
        return (CODE_ERROR);
    reply(client, user);
    return (CODE_SUCCESS);
}
