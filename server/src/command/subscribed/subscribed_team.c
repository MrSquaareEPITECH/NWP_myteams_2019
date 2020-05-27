/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribed_team.c
*/

#include <stdlib.h>

#include "client/client_util.h"
#include "command/subscribed_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "server/server_util.h"
#include "team/team.h"
#include "user/user.h"
#include "user/user_util.h"
#include "util/get_or_error.h"
#include "util/string.h"

static int reply(client_t *client, list_t *users)
{
    char *response = strfmt(RESPONSE_TEAM_SUBSCRIBERS_OK, "Success");
    reply_list_t options = {response, RESPONSE_TEAM_SUBSCRIBERS_START,
        RESPONSE_TEAM_SUBSCRIBERS_END};

    if (client_reply_list(client, &options, users, (to_data_t)(user_to_data)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int subscribed_team(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(argc);

    team_t *team = get_or_error_team(
        client, RESPONSE_TEAM_SUBSCRIBERS_KO, server, argv[1]);

    if (team == NULL)
        return (CODE_ERROR);

    list_t *users = server_get_team_users(server, team);

    if (reply(client, users) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
