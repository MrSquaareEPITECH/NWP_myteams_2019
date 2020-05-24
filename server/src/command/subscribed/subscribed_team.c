/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribed_team.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringext.h>

#include "command/subscribed_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "subscriber/subscriber.h"
#include "team/team.h"
#include "user/user.h"

static team_t *get_team(client_t *client, server_t *server, char **argv)
{
    char *team_uuid = strtrim(argv[1], "\"");
    team_t *team = list_get(server->teams, team_uuid, (compare_t)(team_get_id));
    char *error = NULL;

    if (team == NULL) {
        asprintf(&error, RESPONSE_TEAM_SUBSCRIBERS_KO, "Team doesn't exist");
        list_push(client->queue, error);
    }
    free(team_uuid);
    return (team);
}

static list_t *get_users(server_t *server, team_t *team)
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

static int reply(client_t *client, list_t *users)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_TEAM_SUBSCRIBERS_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_TEAM_SUBSCRIBERS_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = users->begin; node; node = node->next) {
        char *data = NULL;
        user_t *user = (user_t *)(node->obj);

        asprintf(&data, DATA_USER, user->uuid, user->name);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_TEAM_SUBSCRIBERS_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int subscribed_team(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(argc);

    team_t *team = get_team(client, server, argv);

    if (team == NULL)
        return (CODE_ERROR);

    list_t *users = get_users(server, team);

    if (reply(client, users) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
