/*
** EPITECH PROJECT, 2020
** server
** File description:
** create_thread.c
*/

#include <logging_server.h>
#include <stdlib.h>
#include <stringext.h>

#include "channel/channel.h"
#include "channel/channel_util.h"
#include "client/client_util.h"
#include "command/create_internal.h"
#include "def/code.h"
#include "def/event.h"
#include "def/response.h"
#include "server/server_util.h"
#include "subscriber/subscriber.h"
#include "team/team_util.h"
#include "thread/thread.h"
#include "thread/thread_util.h"
#include "util/string.h"

static int validate(client_t *client, int argc, char **argv)
{
    char *error = NULL;
    channel_t *channel = (channel_t *)(client->user->obj);

    if (argc < 3) {
        error = strfmt(RESPONSE_THREAD_CREATE_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (channel_get_thread_name(channel, argv[1])) {
        error = strfmt(RESPONSE_THREAD_CREATE_KO, "Already exists");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (team_get_subscriber(channel->parent, client->user->uuid) == NULL) {
        error = strfmt(RESPONSE_THREAD_CREATE_KO, "Unauthorized");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static thread_t *create(channel_t *channel, const char *user, char **argv)
{
    char *name = strtrim(argv[1], "\"");
    char *description = strtrim(argv[2], "\"");
    thread_t *thread = thread_create(channel, user, name, description);

    free(description);
    free(name);
    return (thread);
}

static int reply(client_t *client, thread_t *thread)
{
    char *response = strfmt(RESPONSE_THREAD_CREATE_OK, "Success");
    char *data = thread_to_data(thread);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, thread_t *thread)
{
    list_t *clients = server_get_team_clients(server, thread->parent->parent);
    char *data = thread_to_data(thread);

    if (server_broadcast(clients, EVENT_THREAD_CREATED, data) == CODE_ERROR)
        return (CODE_ERROR);
    list_clear(clients);
    free(data);
    return (CODE_SUCCESS);
}

int create_thread(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    channel_t *channel = (channel_t *)(client->user->obj);
    thread_t *thread = create(channel, client->user->uuid, argv);

    if (thread == NULL)
        return (CODE_ERROR);
    if (list_push(channel->threads, thread) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, thread) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, thread) == CODE_ERROR)
        return (CODE_ERROR);
    server_event_thread_created(
        channel->uuid, thread->uuid, thread->user, thread->body);
    return (CODE_SUCCESS);
}
