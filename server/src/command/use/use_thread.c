/*
** EPITECH PROJECT, 2020
** server
** File description:
** user_thread.c
*/

#define _GNU_SOURCE

#include <stdio.h>

#include "channel/channel.h"
#include "command/get_error_util.h"
#include "command/use_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "server/server.h"
#include "team/team.h"
#include "thread/thread.h"

static int reply(client_t *client)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_THREAD_USE_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int use_thread(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(argc);

    team_t *team =
        get_error_team(client, RESPONSE_THREAD_USE_KO, server, argv[1]);
    channel_t *channel = NULL;
    thread_t *thread = NULL;

    if (team)
        channel =
            get_error_channel(client, RESPONSE_THREAD_USE_KO, team, argv[2]);
    if (channel)
        thread =
            get_error_thread(client, RESPONSE_THREAD_USE_KO, channel, argv[3]);
    if (thread == NULL)
        return (CODE_ERROR);
    client->user->use = USE_THREAD;
    client->user->obj = thread;
    if (reply(client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
