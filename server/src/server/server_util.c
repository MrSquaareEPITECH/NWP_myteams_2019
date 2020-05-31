/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_util.c
*/

#include "server_util.h"

#include <stdlib.h>
#include <stringext.h>

client_t *server_get_client(server_t *server, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    client_t *client =
        list_get(server->clients, id, (compare_t)(client_get_id));

    free(id);
    return (client);
}

exchange_t *server_get_exchange(server_t *server, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    exchange_t *exchange =
        list_get(server->exchanges, id, (compare_t)(exchange_get_id));

    free(id);
    return (exchange);
}

team_t *server_get_team(server_t *server, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    team_t *team = list_get(server->teams, id, (compare_t)(team_get_id));

    free(id);
    return (team);
}

user_t *server_get_user_id(server_t *server, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    user_t *user = list_get(server->users, id, (compare_t)(user_get_id));

    free(id);
    return (user);
}

user_t *server_get_user_name(server_t *server, const char *name)
{
    char *n = strtrim(name, "\"");
    user_t *user = list_get(server->users, n, (compare_t)(user_get_name));

    free(n);
    return (user);
}
