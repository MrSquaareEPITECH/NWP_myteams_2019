/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_channel.c
*/

#include <stdlib.h>

#include "channel/channel.h"
#include "channel/channel_util.h"
#include "client/client_util.h"
#include "command/list_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "team/team.h"
#include "util/string.h"

static int reply(client_t *client, team_t *team)
{
    char *response = strfmt(RESPONSE_CHANNEL_LIST_OK, "Success");
    reply_list_t options = {
        response, RESPONSE_CHANNEL_LIST_START, RESPONSE_CHANNEL_LIST_END};

    if (client_reply_list(client, &options, team->channels,
            (to_data_t)(channel_to_data)) == CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int list_channel(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    team_t *team = (team_t *)(client->user->obj);

    if (reply(client, team) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
