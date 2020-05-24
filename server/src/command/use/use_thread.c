/*
** EPITECH PROJECT, 2020
** server
** File description:
** user_thread.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stringext.h>

#include "channel/channel.h"
#include "command/use_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "server/server.h"
#include "team/team.h"
#include "thread/thread.h"

static team_t *get_team(client_t *client, server_t *server, char **argv)
{
    char *team_uuid = strtrim(argv[1], "\"");
    team_t *team = list_get(server->teams, team_uuid, (compare_t)(team_get_id));
    char *error = NULL;

    if (team == NULL) {
        asprintf(&error, RESPONSE_THREAD_USE_KO, "Team doesn't exist");
        list_push(client->queue, error);
    }
    free(team_uuid);
    return (team);
}

static channel_t *get_channel(client_t *client, team_t *team, char **argv)
{
    char *channel_uuid = strtrim(argv[2], "\"");
    channel_t *channel =
        list_get(team->channels, channel_uuid, (compare_t)(channel_get_id));
    char *error = NULL;

    if (channel == NULL) {
        asprintf(&error, RESPONSE_THREAD_USE_KO, "Channel doesn't exist");
        list_push(client->queue, error);
    }
    free(channel_uuid);
    return (channel);
}

static thread_t *get_thread(client_t *client, channel_t *channel, char **argv)
{
    char *thread_uuid = strtrim(argv[3], "\"");
    thread_t *thread =
        list_get(channel->threads, thread_uuid, (compare_t)(thread_get_id));
    char *error = NULL;

    if (thread == NULL) {
        asprintf(&error, RESPONSE_THREAD_USE_KO, "Thread doesn't exist");
        list_push(client->queue, error);
    }
    free(thread_uuid);
    return (thread);
}

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

    team_t *team = get_team(client, server, argv);
    channel_t *channel = NULL;
    thread_t *thread = NULL;

    if (team)
        channel = get_channel(client, team, argv);
    if (channel)
        thread = get_thread(client, channel, argv);
    if (thread == NULL)
        return (CODE_ERROR);
    client->user->use = USE_THREAD;
    client->user->obj = thread;
    if (reply(client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
