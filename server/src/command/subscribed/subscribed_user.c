/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribed_user.c
*/

#include <stdlib.h>

#include "client/client_util.h"
#include "command/subscribed_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "server/server_util.h"
#include "team/team.h"
#include "team/team_util.h"
#include "util/string.h"

static int reply(client_t *client, list_t *teams)
{
    char *response = strfmt(RESPONSE_USER_SUBSCRIPTIONS_OK, "Success");
    reply_list_t options = {response, RESPONSE_USER_SUBSCRIPTIONS_START,
        RESPONSE_USER_SUBSCRIPTIONS_END};

    if (client_reply_list(client, &options, teams, (to_data_t)(team_to_data)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int subscribed_user(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(argv);
    (void)(argc);

    list_t *teams = server_get_user_teams(server, client->user);

    if (reply(client, teams) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
