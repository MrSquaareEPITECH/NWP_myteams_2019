/*
** EPITECH PROJECT, 2020
** server
** File description:
** user.c
*/

#define _GNU_SOURCE

#include "user.h"

#include <stdio.h>
#include <stdlib.h>
#include <stringext.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
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

static user_t *get_user(client_t *client, server_t *server, char **argv)
{
    char *user_uuid = strtrim(argv[1], "\"");
    user_t *user = list_get(server->users, user_uuid, (compare_t)(user_get_id));
    char *error = NULL;

    if (user == NULL) {
        asprintf(&error, RESPONSE_USER_INFO_KO, "User doesn't exist");
        list_push(client->queue, error);
    }
    free(user_uuid);
    return (user);
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

    user_t *user = get_user(client, server, argv);

    if (user == NULL)
        return (CODE_ERROR);
    reply(client, user);
    return (CODE_SUCCESS);
}
