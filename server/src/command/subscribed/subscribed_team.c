/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribed_team.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "command/get_error_util.h"
#include "command/get_util.h"
#include "command/subscribed_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "team/team.h"
#include "user/user.h"

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

    team_t *team =
        get_error_team(client, RESPONSE_TEAM_SUBSCRIBERS_KO, server, argv[1]);

    if (team == NULL)
        return (CODE_ERROR);

    list_t *users = get_users(server, team);

    if (reply(client, users) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
