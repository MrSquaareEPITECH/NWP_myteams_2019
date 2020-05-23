/*
** EPITECH PROJECT, 2020
** server
** File description:
** use_team.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stringext.h>

#include "command/use_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "team/team.h"

static team_t *get_team(client_t *client, server_t *server, char **argv)
{
    char *team_uuid = strtrim(argv[1], "\"");
    team_t *team = list_get(server->teams, team_uuid, (compare_t)(team_get_id));
    char *error = NULL;

    if (team == NULL) {
        asprintf(&error, RESPONSE_TEAM_USE_KO, "Team doesn't exist");
        list_push(client->queue, error);
    }
    free(team_uuid);
    return (team);
}

static int reply(client_t *client)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_TEAM_USE_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int use_team(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(argc);

    team_t *team = get_team(client, server, argv);

    if (team == NULL)
        return (CODE_ERROR);
    client->user->use = USE_TEAM;
    client->user->obj = team;
    if (reply(client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
