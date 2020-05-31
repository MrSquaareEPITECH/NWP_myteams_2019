/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_or_error2.c
*/

#include <stdlib.h>
#include <stringext.h>

#include "channel/channel_util.h"
#include "get_or_error.h"
#include "server/server_util.h"
#include "team/team_util.h"
#include "user/user_util.h"
#include "util/string.h"

team_t *get_or_error_team(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    team_t *item = server_get_team_id(server, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "Team doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}

thread_t *get_or_error_thread(
    client_t *client, const char *message, channel_t *channel, const char *uuid)
{
    thread_t *item = channel_get_thread_id(channel, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "Thread doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}

user_t *get_or_error_user_id(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    user_t *item = server_get_user_id(server, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "User doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}

user_t *get_or_error_user_name(
    client_t *client, const char *message, server_t *server, const char *name)
{
    user_t *item = server_get_user_id(server, name);

    if (item == NULL) {
        char *error = strfmt(message, "User doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}
