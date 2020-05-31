/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_team.c
*/

#include "client/client_util.h"
#include "command/info_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "team/team.h"
#include "team/team_util.h"
#include "util/string.h"

static int reply(client_t *client, team_t *team)
{
    char *response = strfmt(RESPONSE_TEAM_INFO_OK, "Success");
    char *data = team_to_data(team);

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
