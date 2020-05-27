/*
** EPITECH PROJECT, 2020
** server
** File description:
** unsubscribe.c
*/

#include "unsubscribe.h"

#include <stdlib.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/response.h"
#include "subscriber/subscriber.h"
#include "team/team.h"
#include "team/team_util.h"
#include "util/get_or_error.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        error = strfmt(RESPONSE_USER_UNSUBSCRIBE_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        error = strfmt(RESPONSE_USER_UNSUBSCRIBE_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, team_t *team)
{
    char *response = strfmt(RESPONSE_USER_UNSUBSCRIBE_OK, "Success");
    char *data = team_to_data(team);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int unsubscribe_command(
    server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    team_t *team = get_or_error_team(
        client, RESPONSE_USER_UNSUBSCRIBE_KO, server, argv[1]);
    subscriber_t *subscriber = NULL;

    if (team)
        subscriber = get_or_error_subscriber(
            client, RESPONSE_USER_UNSUBSCRIBE_KO, team, client->user->uuid);
    if (subscriber == NULL)
        return (CODE_ERROR);
    if (reply(client, team) == CODE_ERROR)
        return (CODE_ERROR);
    list_remove(team->subscribers, subscriber);
    subscriber_delete(subscriber);
    return (CODE_SUCCESS);
}
