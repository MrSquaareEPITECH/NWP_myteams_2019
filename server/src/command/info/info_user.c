/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_user.c
*/

#include "client/client_util.h"
#include "command/info_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "user/user.h"
#include "user/user_util.h"
#include "util/string.h"

static int reply(client_t *client, user_t *user)
{
    char *response = strfmt(RESPONSE_USER_INFO_OK, "Success");
    char *data = user_to_data(user);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int info_user(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    if (reply(client, client->user) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
