/*
** EPITECH PROJECT, 2020
** server
** File description:
** create_team.c
*/

#include <logging_server.h>
#include <stdlib.h>
#include <stringext.h>

#include "client/client_util.h"
#include "command/create_internal.h"
#include "def/code.h"
#include "def/event.h"
#include "def/response.h"
#include "server/server_util.h"
#include "team/team.h"
#include "team/team_util.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    char *error = NULL;

    if (argc < 3) {
        error = strfmt(RESPONSE_TEAM_CREATE_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (server_get_team_name(server, argv[1])) {
        error = strfmt(RESPONSE_TEAM_CREATE_KO, "Already exists");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static team_t *create(char **argv)
{
    char *name = strtrim(argv[1], "\"");
    char *description = strtrim(argv[2], "\"");
    team_t *team = team_create(name, description);

    free(description);
    free(name);
    return (team);
}

static int reply(client_t *client, team_t *team)
{
    char *response = strfmt(RESPONSE_TEAM_CREATE_OK, "Success");
    char *data = team_to_data(team);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, team_t *team)
{
    char *data = team_to_data(team);

    if (server_broadcast(server->clients, EVENT_TEAM_CREATED, data) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int create_team(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    team_t *team = create(argv);

    if (team == NULL)
        return (CODE_ERROR);
    if (list_push(server->teams, team) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, team) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, team) == CODE_ERROR)
        return (CODE_ERROR);
    server_event_team_created(team->uuid, team->name, client->user->uuid);
    return (CODE_SUCCESS);
}
