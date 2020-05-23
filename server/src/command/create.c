/*
** EPITECH PROJECT, 2020
** server
** File description:
** create.c
*/

#define _GNU_SOURCE

#include "create.h"

#include <stdio.h>

#include "create_internal.h"
#include "def/code.h"
#include "def/response.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_GLOBAL_CREATE_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int create_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    int code = 0;

    switch (client->user->use) {
        case USE_CHANNEL:
            code = create_thread(server, client, argc, argv);
            break;
        case USE_SERVER:
            code = create_team(server, client, argc, argv);
            break;
        case USE_TEAM:
            code = create_channel(server, client, argc, argv);
            break;
        case USE_THREAD:
            code = create_comment(server, client, argc, argv);
            break;
    }
    return (code);
}
