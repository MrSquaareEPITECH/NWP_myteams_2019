/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_team.c
*/

#define _GNU_SOURCE

#include <stdio.h>

#include "client/client_util.h"
#include "command/info_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "team/team.h"

static int reply(client_t *client, team_t *team)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_TEAM_INFO_OK, "Success");
    asprintf(&data, DATA_TEAM, team->uuid, team->name, team->description);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int info_team(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    team_t *team = (team_t *)(client->user->obj);

    if (reply(client, team) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
