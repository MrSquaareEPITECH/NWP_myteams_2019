/*
** EPITECH PROJECT, 2020
** server
** File description:
** messages.c
*/

#define _GNU_SOURCE

#include "messages.h"

#include <stdio.h>
#include <string.h>

#include "def/code.h"
#include "def/response.h"
#include "private/private.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_MESSAGE_LIST_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        asprintf(&error, RESPONSE_MESSAGE_LIST_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int messages_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
