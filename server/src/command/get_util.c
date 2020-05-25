/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_util.c
*/

#define _GNU_SOURCE

#include "get_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <stringext.h>

client_t *get_client(server_t *server, const char *arg)
{
    char *user_uuid = strtrim(arg, "\"");
    client_t *item =
        list_get(server->clients, user_uuid, (compare_t)(client_get_id));

    free(user_uuid);
    return (item);
}

channel_t *get_channel(team_t *team, const char *arg)
{
    char *channel_uuid = strtrim(arg, "\"");
    channel_t *item =
        list_get(team->channels, channel_uuid, (compare_t)(channel_get_id));

    free(channel_uuid);
    return (item);
}

team_t *get_team(server_t *server, const char *arg)
{
    char *team_uuid = strtrim(arg, "\"");
    team_t *item = list_get(server->teams, team_uuid, (compare_t)(team_get_id));

    free(team_uuid);
    return (item);
}

list_t *get_teams(server_t *server, client_t *client)
{
    list_t *teams = list_create();

    for (node_t *node = server->teams->begin; node; node = node->next) {
        team_t *item = (team_t *)(node->obj);
        subscriber_t *subscriber = list_get(item->subscribers,
            client->user->uuid, (compare_t)(subscriber_get_id));

        if (subscriber == NULL)
            continue;
        list_push(teams, item);
    }
    return (teams);
}

thread_t *get_thread(channel_t *channel, const char *arg)
{
    char *thread_uuid = strtrim(arg, "\"");
    thread_t *item =
        list_get(channel->threads, thread_uuid, (compare_t)(thread_get_id));

    free(thread_uuid);
    return (item);
}

user_t *get_user_id(server_t *server, const char *arg)
{
    char *user_uuid = strtrim(arg, "\"");
    user_t *item = list_get(server->users, user_uuid, (compare_t)(user_get_id));

    free(user_uuid);
    return (item);
}

user_t *get_user_name(server_t *server, const char *arg)
{
    char *user_uuid = strtrim(arg, "\"");
    user_t *item = list_get(server->users, user_uuid, (compare_t)(user_get_name));

    free(user_uuid);
    return (item);
}

list_t *get_users(server_t *server, team_t *team)
{
    list_t *users = list_create();

    for (node_t *node = team->subscribers->begin; node; node = node->next) {
        subscriber_t *subscriber = (subscriber_t *)(node->obj);
        user_t *user =
            list_get(server->users, subscriber->uuid, (compare_t)(user_get_id));

        if (user == NULL)
            continue;
        list_push(users, user);
    }
    return (users);
}
