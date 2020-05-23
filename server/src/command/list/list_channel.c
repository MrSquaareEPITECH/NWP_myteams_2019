/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_channel.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "channel/channel.h"
#include "command/list_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "team/team.h"

static int reply(client_t *client, team_t *team)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_CHANNEL_LIST_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_CHANNEL_LIST_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = team->channels->begin; node; node = node->next) {
        char *data = NULL;
        channel_t *channel = (channel_t *)(node->obj);

        asprintf(&data, DATA_CHANNEL, channel->uuid, channel->name,
            channel->description);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_CHANNEL_LIST_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int list_channel(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    team_t *team = (team_t *)(client->user->obj);

    reply(client, team);
    return (CODE_SUCCESS);
}
