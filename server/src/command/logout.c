/*
** EPITECH PROJECT, 2020
** server
** File description:
** logout.c
*/

#include "logout.h"

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

    if (client->state != CLIENT_LOGGED) {
        error = strfmt(RESPONSE_USER_LOGOUT_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, user_t *user)
{
    char *response = strfmt(RESPONSE_USER_LOGOUT_OK, "Success");
    char *data = user_to_data(user);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, user_t *user)
{
    char *data = user_to_data(user);

    if (server_broadcast(server->clients, EVENT_USER_LOGGEDOUT, data) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int logout_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *user = client->user;

    user->status = 0;
    if (reply(client, user) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, user) == CODE_ERROR)
        return (CODE_ERROR);
    client->state = CLIENT_CONNECTED;
    client->user = NULL;
    return (CODE_SUCCESS);
}
