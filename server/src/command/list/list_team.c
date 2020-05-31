/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_team.c
*/

#include <stdlib.h>

#include "client/client_util.h"
#include "command/list_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "team/team.h"
#include "team/team_util.h"
#include "util/string.h"

static int reply(client_t *client, server_t *server)
{
    char *response = strfmt(RESPONSE_TEAM_LIST_OK, "Success");
    reply_list_t options = {
        response, RESPONSE_TEAM_LIST_START, RESPONSE_TEAM_LIST_END};

    if (client_reply_list(client, &options, server->teams,
            (to_data_t)(team_to_data)) == CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int list_team(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    if (reply(client, server) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
