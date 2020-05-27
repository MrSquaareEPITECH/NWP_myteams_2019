/*
** EPITECH PROJECT, 2020
** server
** File description:
** login.c
*/

#include "login.h"

#include <stdlib.h>
#include <stringext.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/event.h"
#include "def/response.h"
#include "server/server_util.h"
#include "user/user.h"
#include "user/user_util.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state == CLIENT_LOGGED) {
        error = strfmt(RESPONSE_USER_LOGIN_KO, "Already logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        error = strfmt(RESPONSE_USER_LOGIN_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static user_t *create(char **argv)
{
    char *name = strtrim(argv[1], "\"");
    user_t *user = user_create(name);

    free(name);
    return (user);
}

static int reply(client_t *client, user_t *user)
{
    char *response = strfmt(RESPONSE_USER_LOGIN_OK, "Success");
    char *data = user_to_data(user);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, user_t *user)
{
    char *data = user_to_data(user);

    if (server_broadcast(server->clients, EVENT_USER_LOGGEDIN, data) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int login_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *user = server_get_user_name(server, argv[1]);

    if (user == NULL) {
        user = create(argv);
        list_push(server->users, user);
    }

    client->state = CLIENT_LOGGED;
    client->user = user;
    if (reply(client, user) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, user) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
