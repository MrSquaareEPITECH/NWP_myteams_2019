/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribed_user.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "command/subscribed_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "subscriber/subscriber.h"
#include "team/team.h"

static list_t *get_teams(server_t *server, client_t *client)
{
    list_t *teams = list_create();

    for (node_t *node = server->teams->begin; node; node = node->next) {
        team_t *team = (team_t *)(node->obj);
        subscriber_t *subscriber = list_get(team->subscribers,
            client->user->uuid, (compare_t)(subscriber_get_id));

        if (subscriber == NULL)
            continue;
        list_push(teams, team);
    }
    return (teams);
}

static int reply(client_t *client, list_t *teams)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_USER_SUBSCRIPTIONS_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_USER_SUBSCRIPTIONS_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = teams->begin; node; node = node->next) {
        char *data = NULL;
        team_t *team = (team_t *)(node->obj);

        asprintf(&data, DATA_TEAM, team->uuid, team->name, team->description);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_USER_SUBSCRIPTIONS_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int subscribed_user(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(argv);
    (void)(argc);

    list_t *teams = get_teams(server, client);

    if (reply(client, teams) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
