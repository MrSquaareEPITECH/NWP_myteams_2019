/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_or_error.c
*/

#include "get_or_error.h"

#include <stdlib.h>
#include <stringext.h>

#include "channel/channel_util.h"
#include "server/server_util.h"
#include "team/team_util.h"
#include "user/user_util.h"
#include "util/string.h"

channel_t *get_or_error_channel(
    client_t *client, const char *message, team_t *team, const char *uuid)
{
    channel_t *item = team_get_channel_id(team, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "Channel doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}

client_t *get_or_error_client(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    client_t *item = server_get_client(server, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "Client doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}

exchange_t *get_or_error_exchange(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    exchange_t *item = server_get_exchange(server, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "Exchange doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}

private_t *get_or_error_private(
    client_t *client, const char *message, user_t *user, const char *uuid)
{
    private_t *item = user_get_private(user, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "Private doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}

subscriber_t *get_or_error_subscriber(
    client_t *client, const char *message, team_t *team, const char *uuid)
{
    subscriber_t *item = team_get_subscriber(team, uuid);
    char *trim_uuid = strtrim(uuid, "\"");

    if (item == NULL) {
        char *error = strfmt(message, "Subscriber doesn't exist", trim_uuid);

        list_push(client->queue, error);
    }
    free(trim_uuid);
    return (item);
}
