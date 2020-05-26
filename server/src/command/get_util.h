/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_util.h
*/

#ifndef SERVER_SRC_COMMAND_GET_UTIL_H
#define SERVER_SRC_COMMAND_GET_UTIL_H

#include "channel/channel.h"
#include "client/client.h"
#include "conversation/conversation.h"
#include "list/list.h"
#include "private/private.h"
#include "server/server.h"
#include "subscriber/subscriber.h"
#include "team/team.h"
#include "thread/thread.h"
#include "user/user.h"

client_t *get_client(server_t *server, const char *arg);
channel_t *get_channel(team_t *team, const char *arg);
conversation_t *get_conversion(server_t *server, const char *arg);
private_t *get_private(user_t *user, const char *arg);
team_t *get_team(server_t *server, const char *arg);
list_t *get_teams(server_t *server, client_t *client);
thread_t *get_thread(channel_t *channel, const char *arg);
user_t *get_user_id(server_t *server, const char *arg);
user_t *get_user_name(server_t *server, const char *arg);
list_t *get_users(server_t *server, team_t *team);

#endif // SERVER_SRC_COMMAND_GET_UTIL_H
