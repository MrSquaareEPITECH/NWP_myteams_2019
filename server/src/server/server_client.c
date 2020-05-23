/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_client.c
*/

#include "server_client.h"

#include <arrayext.h>
#include <stdlib.h>

#include "client/client.h"
#include "def/code.h"
#include "helper/command.h"

int server_client_add(server_t *server, client_t *client)
{
    if (list_push(server->clients, client) == CODE_ERROR)
        return (CODE_ERROR);
    select_set(server->sel, client->sock, SELECT_READ | SELECT_WRITE);
    return (CODE_SUCCESS);
}

int server_client_remove(server_t *server, client_t *client)
{
    if (list_remove(server->clients, client) == CODE_ERROR)
        return (CODE_ERROR);
    select_clear(server->sel, client->sock, SELECT_READ | SELECT_WRITE);
    client_delete(client);
    return (CODE_SUCCESS);
}

int server_client_execute(server_t *server, client_t *client)
{
    int argc = 0;
    char **argv = NULL;

    if (server_client_receive(server, client, &argc, &argv) == CODE_ERROR)
        return (CODE_ERROR);
    if (argc <= 0)
        return (CODE_ERROR);

    const command_t *command = command_get(argv[0]);

    if (command == NULL)
        return (CODE_ERROR);
    if (command->func(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);
    arrfree((void **)(argv), free);
    return (CODE_SUCCESS);
}

int server_client_notify(server_t *server, client_t *client)
{
    while (client->queue->begin) {
        node_t *node = client->queue->begin;

        if (server_client_send(server, client, node->obj) == CODE_ERROR)
            return (CODE_ERROR);
        list_pop(client->queue);
        free(node->obj);
        free(node);
    }
    return (CODE_SUCCESS);
}
