/*
** EPITECH PROJECT, 2020
** server
** File description:
** use_team.c
*/

#define _GNU_SOURCE

#include <stdio.h>

#include "command/get_error_util.h"
#include "command/use_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "team/team.h"

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

    team_t *team =
        get_error_team(client, RESPONSE_TEAM_USE_KO, server, argv[1]);

    if (team == NULL)
        return (CODE_ERROR);
    client->user->use = USE_TEAM;
    client->user->obj = team;
    if (reply(client) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
