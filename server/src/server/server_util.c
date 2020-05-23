/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_util.c
*/

#include "server_util.h"

#include <string.h>

#include "client/client.h"
#include "def/code.h"

int server_broadcast(server_t *server, const char *event, const char *data)
{
    for (node_t *node = server->clients->begin; node; node = node->next) {
        client_t *client = node->obj;

        if (list_push(client->queue, strdup(event)) == CODE_ERROR)
            return (CODE_ERROR);
        if (list_push(client->queue, strdup(data)) == CODE_ERROR)
            return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}
