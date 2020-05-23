/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_team.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "command/list_internal.h"
#include "team/team.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"

static int reply(client_t *client, server_t *server)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_TEAM_LIST_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_TEAM_LIST_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = server->teams->begin; node; node = node->next) {
        char *data = NULL;
        team_t *team = (team_t *)(node->obj);

        asprintf(&data, DATA_TEAM, team->uuid, team->name, team->description);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_TEAM_LIST_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int list_team(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    reply(client, server);
    return (CODE_SUCCESS);
}
