/*
** EPITECH PROJECT, 2020
** server
** File description:
** user.c
*/

#include "user.h"

#include "client/client_util.h"
#include "def/code.h"
#include "def/response.h"
#include "user/user.h"
#include "user/user_util.h"
#include "util/get_or_error.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        error = strfmt(RESPONSE_USER_INFO_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        error = strfmt(RESPONSE_USER_INFO_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, user_t *user)
{
    char *response = strfmt(RESPONSE_USER_INFO_OK, "Success");
    char *data = user_to_data(user);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int user_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *user =
        get_or_error_user_id(client, RESPONSE_USER_INFO_KO, server, argv[1]);

    if (user == NULL)
        return (CODE_ERROR);
    if (reply(client, user) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
