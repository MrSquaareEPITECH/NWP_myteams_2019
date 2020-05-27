/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_channel.c
*/

#include <stdlib.h>

#include "channel/channel.h"
#include "client/client_util.h"
#include "command/list_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "thread/thread.h"
#include "thread/thread_util.h"
#include "util/string.h"

static int reply(client_t *client, channel_t *channel)
{
    char *response = strfmt(RESPONSE_THREAD_LIST_OK, "Success");
    reply_list_t options = {
        response, RESPONSE_THREAD_LIST_START, RESPONSE_THREAD_LIST_END};

    if (client_reply_list(client, &options, channel->threads,
            (to_data_t)(thread_to_data)) == CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int list_thread(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    channel_t *channel = (channel_t *)(client->user->obj);

    if (reply(client, channel) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
