/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_func.c
*/

#include "server_internal.h"

#include <stdio.h>

#include "def/code.h"
#include "server_client.h"

int server_accept(server_t *server)
{
    if (!select_is_set(server->sel, server->sock, SELECT_READ))
        return (CODE_SUCCESS);

    printf("server_accept\n"); // TODO: Debug

    client_t *client = client_create();

    if (socket_accept(client->sock, server->sock) == CODE_INVALID)
        return (CODE_ERROR);
    if (server_client_add(server, client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int server_clear(server_t *server)
{
    for (node_t *node = server->clients->begin; node; node = node->next) {
        client_t *client = client_c(node->obj);

        if (client->state != CLIENT_DISCONNECTED)
            continue;

        printf("server_clear\n"); // TODO: Debug

        if (server_client_remove(server, client) == CODE_ERROR)
            return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int server_execute(server_t *server)
{
    for (node_t *node = server->clients->begin; node; node = node->next) {
        client_t *client = client_c(node->obj);

        server_client_execute(server, client);
        server_client_notify(server, client);
    }
    return (CODE_SUCCESS);
}
