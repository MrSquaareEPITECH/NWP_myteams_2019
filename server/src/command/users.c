/*
** EPITECH PROJECT, 2020
** server
** File description:
** users.c
*/

#include "users.h"

#include <stdlib.h>
#include <string.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/response.h"
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
        error = strfmt(RESPONSE_USER_LIST_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, server_t *server)
{
    char *response = strfmt(RESPONSE_USER_LIST_OK, "Success");
    reply_list_t options = {
        response, RESPONSE_USER_LIST_START, RESPONSE_USER_LIST_END};

    if (client_reply_list(client, &options, server->users,
            (to_data_t)(user_to_data)) == CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int users_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, server) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
