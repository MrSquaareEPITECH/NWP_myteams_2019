/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribe.c
*/

#define _GNU_SOURCE

#include "subscribe.h"

#include <stdio.h>
#include <stdlib.h>
#include <stringext.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
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

static team_t *get_team(client_t *client, server_t *server, char **argv)
{
    char *team_uuid = strtrim(argv[1], "\"");
    team_t *team = list_get(server->teams, team_uuid, (compare_t)(team_get_id));
    char *error = NULL;

    if (team == NULL) {
        asprintf(&error, RESPONSE_USER_SUBSCRIBE_KO, "Team doesn't exist");
        list_push(client->queue, error);
    }
    free(team_uuid);
    return (team);
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

    team_t *team = get_team(client, server, argv);
    subscriber_t *subscriber = subscriber_create(client->user->uuid);

    if (team == NULL)
        return (CODE_ERROR);
    list_push(team->subscribers, subscriber);
    reply(client, team);
    return (CODE_SUCCESS);
}
