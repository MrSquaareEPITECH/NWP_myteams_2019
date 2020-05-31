/*
** EPITECH PROJECT, 2020
** server
** File description:
** create_channel.c
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
#include "team/team.h"
#include "team/team_util.h"
#include "util/string.h"

static int validate(client_t *client, int argc, char **argv)
{
    char *error = NULL;
    team_t *team = (team_t *)(client->user->obj);

    if (argc < 3) {
        error = strfmt(RESPONSE_CHANNEL_CREATE_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (team_get_channel_name(team, argv[1])) {
        error = strfmt(RESPONSE_CHANNEL_CREATE_KO, "Already exists");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (team_get_subscriber(team, client->user->uuid) == NULL) {
        error = strfmt(RESPONSE_CHANNEL_CREATE_KO, "Unauthorized");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static channel_t *create(team_t *team, char **argv)
{
    char *name = strtrim(argv[1], "\"");
    char *description = strtrim(argv[2], "\"");
    channel_t *channel = channel_create(team, name, description);

    free(description);
    free(name);
    return (channel);
}

static int reply(client_t *client, channel_t *channel)
{
    char *response = strfmt(RESPONSE_CHANNEL_CREATE_OK, "Success");
    char *data = channel_to_data(channel);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, channel_t *channel)
{
    list_t *clients = server_get_team_clients(server, channel->parent);
    char *data = channel_to_data(channel);

    if (server_broadcast(clients, EVENT_CHANNEL_CREATED, data) == CODE_ERROR)
        return (CODE_ERROR);
    list_clear(clients);
    free(data);
    return (CODE_SUCCESS);
}

int create_channel(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    team_t *team = (team_t *)(client->user->obj);
    channel_t *channel = create(team, argv);

    if (channel == NULL)
        return (CODE_ERROR);
    if (list_push(team->channels, channel) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, channel) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, channel) == CODE_ERROR)
        return (CODE_ERROR);
    server_event_channel_created(team->uuid, channel->uuid, channel->name);
    return (CODE_SUCCESS);
}
