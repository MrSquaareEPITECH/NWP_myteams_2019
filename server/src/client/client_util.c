/*
** EPITECH PROJECT, 2020
** server
** File description:
** client_util.c
*/

#include "client_util.h"

#include <string.h>

#include "def/code.h"

int client_reply(client_t *client, char *message, char *data)
{
    if (list_push(client->queue, message) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int client_reply_list(
    client_t *client, reply_list_t *options, list_t *list, to_data_t to_data)
{
    if (list_push(client->queue, strdup(options->message)) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(options->start)) == CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = list->begin; node; node = node->next) {
        char *data = to_data(node->obj);

        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(options->end)) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}
