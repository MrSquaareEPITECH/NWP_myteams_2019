/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_or_error.c
*/

#include "get_or_error.h"

#include "channel/channel_util.h"
#include "server/server_util.h"
#include "team/team_util.h"
#include "user/user_util.h"
#include "util/string.h"

channel_t *get_or_error_channel(
    client_t *client, const char *message, team_t *team, const char *uuid)
{
    channel_t *item = team_get_channel(team, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "Channel doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}

client_t *get_or_error_client(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    client_t *item = server_get_client(server, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "Client doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}

exchange_t *get_or_error_exchange(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    exchange_t *item = server_get_exchange(server, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "Exchange doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}

private_t *get_or_error_private(
    client_t *client, const char *message, user_t *user, const char *uuid)
{
    private_t *item = user_get_private(user, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "Private doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}

subscriber_t *get_or_error_subscriber(
    client_t *client, const char *message, team_t *team, const char *uuid)
{
    subscriber_t *item = team_get_subscriber(team, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "Subscriber doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}

team_t *get_or_error_team(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    team_t *item = server_get_team(server, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "Team doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}

thread_t *get_or_error_thread(
    client_t *client, const char *message, channel_t *channel, const char *uuid)
{
    thread_t *item = channel_get_thread(channel, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "Thread doesn't exist");

        list_push(client->queue, error);
    }
    return (item);
}

user_t *get_or_error_user_id(
    client_t *client, const char *message, server_t *server, const char *uuid)
{
    user_t *item = server_get_user_id(server, uuid);

    if (item == NULL) {
        char *error = strfmt(message, "User doesn't exist");

        list_push(client->queue, error);
    }
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
