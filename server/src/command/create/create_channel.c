/*
** EPITECH PROJECT, 2020
** server
** File description:
** create_channel.c
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
#include "team/team.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (argc < 3) {
        asprintf(&error, RESPONSE_CHANNEL_CREATE_KO, "Missing argument");
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
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_CHANNEL_CREATE_OK, "Success");
    asprintf(&data, DATA_CHANNEL, channel->uuid, channel->name,
        channel->description);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, channel_t *channel)
{
    char *data = NULL;

    asprintf(&data, DATA_CHANNEL, channel->uuid, channel->name,
        channel->description);
    if (server_broadcast(server, EVENT_CHANNEL_CREATED, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int create_channel(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
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
    return (CODE_SUCCESS);
}