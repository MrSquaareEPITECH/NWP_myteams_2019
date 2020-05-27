/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_or_error.h
*/

#ifndef SERVER_SRC_UTIL_GET_OR_ERROR_H
#define SERVER_SRC_UTIL_GET_OR_ERROR_H

#include "channel/channel.h"
#include "client/client.h"
#include "exchange/exchange.h"
#include "private/private.h"
#include "server/server.h"
#include "subscriber/subscriber.h"
#include "team/team.h"
#include "thread/thread.h"
#include "user/user.h"

channel_t *get_or_error_channel(
    client_t *client, const char *message, team_t *team, const char *uuid);
client_t *get_or_error_client(
    client_t *client, const char *message, server_t *server, const char *uuid);
exchange_t *get_or_error_exchange(
    client_t *client, const char *message, server_t *server, const char *uuid);
private_t *get_or_error_private(
    client_t *client, const char *message, user_t *user, const char *uuid);
subscriber_t *get_or_error_subscriber(
    client_t *client, const char *message, team_t *team, const char *uuid);
team_t *get_or_error_team(
    client_t *client, const char *message, server_t *server, const char *uuid);
thread_t *get_or_error_thread(client_t *client, const char *message,
    channel_t *channel, const char *uuid);
user_t *get_or_error_user_id(
    client_t *client, const char *message, server_t *server, const char *uuid);
user_t *get_or_error_user_name(
    client_t *client, const char *message, server_t *server, const char *name);

#endif // SERVER_SRC_UTIL_GET_OR_ERROR_H
