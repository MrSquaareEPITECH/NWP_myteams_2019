/*
** EPITECH PROJECT, 2020
** server
** File description:
** create_thread.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stringext.h>

#include "channel/channel.h"
#include "client/client_util.h"
#include "command/create_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/event.h"
#include "def/response.h"
#include "server/server_util.h"
#include "thread/thread.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (argc < 3) {
        asprintf(&error, RESPONSE_THREAD_CREATE_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static thread_t *create(channel_t *channel, char **argv)
{
    char *name = strtrim(argv[1], "\"");
    char *description = strtrim(argv[2], "\"");
    thread_t *thread = thread_create(channel, name, description);

    free(description);
    free(name);
    return (thread);
}

static int reply(client_t *client, thread_t *thread)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_THREAD_CREATE_OK, "Success");
    asprintf(&data, DATA_THREAD, thread->uuid, thread->timestamp, thread->name,
        thread->body);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, thread_t *thread)
{
    char *data = NULL;

    asprintf(&data, DATA_THREAD, thread->uuid, thread->timestamp, thread->name,
        thread->body);
    if (server_broadcast(server, EVENT_THREAD_CREATED, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int create_thread(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    channel_t *channel = (channel_t *)(client->user->obj);
    thread_t *thread = create(channel, argv);

    if (thread == NULL)
        return (CODE_ERROR);
    if (list_push(channel->threads, thread) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, thread) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, thread) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
