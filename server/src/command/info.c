/*
** EPITECH PROJECT, 2020
** server
** File description:
** info.c
*/

#include "info.h"

#include "def/code.h"
#include "def/response.h"
#include "info_internal.h"
#include "util/string.h"

static int info_validation(
    server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        error = strfmt(RESPONSE_GLOBAL_INFO_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int info_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (info_validation(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    int code = 0;

    switch (client->user->use) {
        case USE_CHANNEL:
            code = info_channel(server, client, argc, argv);
            break;
        case USE_SERVER:
            code = info_user(server, client, argc, argv);
            break;
        case USE_TEAM:
            code = info_team(server, client, argc, argv);
            break;
        case USE_THREAD:
            code = info_thread(server, client, argc, argv);
            break;
    }
    return (code);
}
