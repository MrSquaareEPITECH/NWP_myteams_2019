/*
** EPITECH PROJECT, 2020
** cli
** File description:
** client_internal.c
*/

#include "client_internal.h"

#include <arrayext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringext.h>

#include "def/code.h"
#include "def/help.h"
#include "response/response.h"

int client_input(client_t *client)
{
    if (!select_is_set(client->sel, &client->input, SELECT_READ))
        return (CODE_ERROR);

    char *message = NULL;
    size_t len = 0;

    if (getline(&message, &len, stdin) == CODE_ERROR)
        return (CODE_ERROR);

    char *trim = strtrim(message, " \t");

    if (strcmp(trim, "/help\n") == 0)
        printf("%s", HELP);
    else
        list_push(client->queue, trim);
    return (CODE_SUCCESS);
}

int client_execute(client_t *client)
{
    int argc = 0;
    char **argv = NULL;

    if (client_receive(client, &argc, &argv) == CODE_ERROR)
        return (CODE_ERROR);
    if (argc < 1)
        return (CODE_ERROR);

    const response_t *response = response_get(argv[0]);

    if (response == NULL)
        return (CODE_ERROR);
    if (response->func(client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);
    arrfree((void **)(argv), free);
    return (CODE_SUCCESS);
}

int client_notify(client_t *client)
{
    while (client->queue->begin) {
        node_t *node = client->queue->begin;

        if (client_send(client, node->obj) == CODE_ERROR)
            return (CODE_ERROR);
        list_pop(client->queue);
        free(node->obj);
        free(node);
    }
    return (CODE_SUCCESS);
}
