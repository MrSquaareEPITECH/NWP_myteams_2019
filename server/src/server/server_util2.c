/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_util2.c
*/

#include <stdlib.h>
#include <string.h>
#include <stringext.h>

#include "client/client.h"
#include "client/client_util.h"
#include "def/code.h"
#include "server_util.h"
#include "subscriber/subscriber.h"

team_t *server_get_team_name(server_t *server, const char *name)
{
    char *n = strtrim(name, "\"");
    team_t *team = list_get(server->teams, n, (compare_t)(team_get_name));

    free(n);
    return (team);
}

list_t *server_get_team_clients(server_t *server, team_t *team)
{
    list_t *clients = list_create();

    for (node_t *node = team->subscribers->begin; node; node = node->next) {
        subscriber_t *subscriber = (subscriber_t *)(node->obj);
        client_t *client = list_get(
            server->clients, subscriber->uuid, (compare_t)(client_get_id));

        if (client == NULL)
            continue;
        list_push(clients, client);
    }
    return (clients);
}

list_t *server_get_team_users(server_t *server, team_t *team)
{
    list_t *users = list_create();

    for (node_t *node = team->subscribers->begin; node; node = node->next) {
        subscriber_t *subscriber = (subscriber_t *)(node->obj);
        user_t *user =
            list_get(server->users, subscriber->uuid, (compare_t)(user_get_id));

        if (user == NULL)
            continue;
        list_push(users, user);
    }
    return (users);
}

list_t *server_get_user_teams(server_t *server, user_t *user)
{
    list_t *teams = list_create();

    for (node_t *node = server->teams->begin; node; node = node->next) {
        team_t *item = (team_t *)(node->obj);
        subscriber_t *subscriber = list_get(
            item->subscribers, user->uuid, (compare_t)(subscriber_get_id));

        if (subscriber == NULL)
            continue;
        list_push(teams, item);
    }
    return (teams);
}

int server_broadcast(list_t *clients, const char *event, const char *data)
{
    for (node_t *node = clients->begin; node; node = node->next) {
        client_t *client = (client_t *)(node->obj);

        if (client->user == NULL)
            continue;

        char *ev = strdup(event);
        char *d = strdup(data);

        if (client_reply(client, ev, d) == CODE_ERROR)
            return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}
