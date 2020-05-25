/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_error_util.h
*/

#ifndef SERVER_SRC_COMMAND_GET_ERROR_UTIL_H
#define SERVER_SRC_COMMAND_GET_ERROR_UTIL_H

#include "channel/channel.h"
#include "client/client.h"
#include "server/server.h"
#include "team/team.h"
#include "thread/thread.h"
#include "user/user.h"

client_t *get_error_client(
    client_t *client, const char *response, server_t *server, const char *arg);
channel_t *get_error_channel(
    client_t *client, const char *response, team_t *team, const char *arg);
team_t *get_error_team(
    client_t *client, const char *response, server_t *server, const char *arg);
thread_t *get_error_thread(client_t *client, const char *response,
    channel_t *channel, const char *arg);
user_t *get_error_user(
    client_t *client, const char *response, server_t *server, const char *arg);

#endif // SERVER_SRC_COMMAND_GET_ERROR_UTIL_H
