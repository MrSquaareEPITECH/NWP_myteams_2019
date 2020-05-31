/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_util.h
*/

#ifndef SERVER_SRC_SERVER_SERVER_UTIL_H
#define SERVER_SRC_SERVER_SERVER_UTIL_H

#include "client/client.h"
#include "exchange/exchange.h"
#include "list/list.h"
#include "server.h"
#include "team/team.h"
#include "user/user.h"

client_t *server_get_client(server_t *server, const char *uuid);
exchange_t *server_get_exchange(server_t *server, const char *uuid);
team_t *server_get_team_id(server_t *server, const char *uuid);
team_t *server_get_team_name(server_t *server, const char *name);
list_t *server_get_team_clients(server_t *server, team_t *team);
list_t *server_get_team_users(server_t *server, team_t *team);
user_t *server_get_user_id(server_t *server, const char *uuid);
user_t *server_get_user_name(server_t *server, const char *name);
list_t *server_get_user_teams(server_t *server, user_t *user);
int server_broadcast(list_t *clients, const char *event, const char *data);

#endif // SERVER_SRC_SERVER_SERVER_UTIL_H
