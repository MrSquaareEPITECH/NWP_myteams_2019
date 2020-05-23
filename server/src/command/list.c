/*
** EPITECH PROJECT, 2020
** server
** File description:
** list.c
*/

#define _GNU_SOURCE

#include "list.h"

#include <stdio.h>

#include "def/code.h"
#include "def/response.h"
#include "list_internal.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_GLOBAL_LIST_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int list_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    int code = 0;

    switch (client->user->use) {
        case USE_CHANNEL:
            code = list_thread(server, client, argc, argv);
            break;
        case USE_SERVER:
            code = list_team(server, client, argc, argv);
            break;
        case USE_TEAM:
            code = list_channel(server, client, argc, argv);
            break;
        case USE_THREAD:
            code = list_comment(server, client, argc, argv);
            break;
    }
    return (code);
}
