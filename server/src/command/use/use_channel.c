/*
** EPITECH PROJECT, 2020
** server
** File description:
** use_channel.c
*/

#define _GNU_SOURCE

#include <stdio.h>

#include "channel/channel.h"
#include "command/get_error_util.h"
#include "command/use_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "team/team.h"

static int reply(client_t *client)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_CHANNEL_USE_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int use_channel(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(argc);

    team_t *team =
        get_error_team(client, RESPONSE_CHANNEL_USE_KO, server, argv[1]);
    channel_t *channel = NULL;

    if (team)
        channel =
            get_error_channel(client, RESPONSE_CHANNEL_USE_KO, team, argv[2]);
    if (channel == NULL)
        return (CODE_ERROR);
    client->user->use = USE_CHANNEL;
    client->user->obj = channel;
    if (reply(client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
