/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_channel.c
*/

#include "channel/channel.h"
#include "channel/channel_util.h"
#include "client/client_util.h"
#include "command/info_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "util/string.h"

static int reply(client_t *client, channel_t *channel)
{
    char *response = strfmt(RESPONSE_CHANNEL_INFO_OK, "Success");
    char *data = channel_to_data(channel);

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
