/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribed.c
*/

#define _GNU_SOURCE

#include "subscribed.h"

#include <stdio.h>

#include "def/code.h"
#include "def/response.h"
#include "subscribed_internal.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_GLOBAL_SUBSCRIBED_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int subscribed_command(
    server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    switch (argc) {
        case 1:
            subscribed_user(server, client, argc, argv);
            break;
        default:
            subscribed_team(server, client, argc, argv);
            break;
    }
    return (CODE_SUCCESS);
}
