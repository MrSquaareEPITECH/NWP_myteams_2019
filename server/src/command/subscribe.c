/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribe.c
*/

#define _GNU_SOURCE

#include "subscribe.h"

#include <stdio.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "get_error_util.h"
#include "subscriber/subscriber.h"
#include "team/team.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_USER_SUBSCRIBE_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        asprintf(&error, RESPONSE_USER_SUBSCRIBE_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, team_t *team)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_USER_SUBSCRIBE_OK, "Success");
    asprintf(&data, DATA_TEAM, team->uuid, team->name, team->description);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int subscribe_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    team_t *team =
        get_error_team(client, RESPONSE_USER_SUBSCRIBE_KO, server, argv[1]);

    if (team == NULL)
        return (CODE_ERROR);

    subscriber_t *subscriber = subscriber_create(client->user->uuid);

    list_push(team->subscribers, subscriber);
    reply(client, team);
    return (CODE_SUCCESS);
}
