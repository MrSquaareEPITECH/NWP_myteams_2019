/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_thread.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "channel/channel.h"
#include "command/list_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "thread/thread.h"

static int reply(client_t *client, channel_t *channel)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_THREAD_LIST_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_THREAD_LIST_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = channel->threads->begin; node; node = node->next) {
        char *data = NULL;
        thread_t *thread = (thread_t *)(node->obj);

        asprintf(&data, DATA_THREAD, thread->uuid, thread->timestamp,
            thread->name, thread->body);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_THREAD_LIST_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int list_thread(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    channel_t *channel = (channel_t *)(client->user->obj);

    reply(client, channel);
    return (CODE_SUCCESS);
}
