/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_channel.c
*/

#define _GNU_SOURCE

#include <stdio.h>

#include "channel/channel.h"
#include "client/client_util.h"
#include "command/info_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"

static int reply(client_t *client, channel_t *channel)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_CHANNEL_INFO_OK, "Success");
    asprintf(&data, DATA_CHANNEL, channel->uuid, channel->name,
        channel->description);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int info_channel(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    channel_t *channel = (channel_t *)(client->user->obj);

    if (reply(client, channel) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
