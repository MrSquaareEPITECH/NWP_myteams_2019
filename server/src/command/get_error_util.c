/*
** EPITECH PROJECT, 2020
** server
** File description:
** get_error_util.c
*/

#define _GNU_SOURCE

#include "get_error_util.h"

#include <stdio.h>

#include "get_util.h"

client_t *get_error_client(
    client_t *client, const char *response, server_t *server, const char *arg)
{
    client_t *item = get_client(server, arg);
    char *error = NULL;

    if (item == NULL) {
        asprintf(&error, response, "Client doesn't exist");
        list_push(client->queue, error);
    }
    return (client);
}

channel_t *get_error_channel(
    client_t *client, const char *response, team_t *team, const char *arg)
{
    channel_t *item = get_channel(team, arg);
    char *error = NULL;

    if (item == NULL) {
        asprintf(&error, response, "Channel doesn't exist");
        list_push(client->queue, error);
    }
    return (item);
}

team_t *get_error_team(
    client_t *client, const char *response, server_t *server, const char *arg)
{
    team_t *item = get_team(server, arg);
    char *error = NULL;

    if (item == NULL) {
        asprintf(&error, response, "Team doesn't exist");
        list_push(client->queue, error);
    }
    return (item);
}

thread_t *get_error_thread(
    client_t *client, const char *response, channel_t *channel, const char *arg)
{
    thread_t *item = get_thread(channel, arg);
    char *error = NULL;

    if (item == NULL) {
        asprintf(&error, response, "Thread doesn't exist");
        list_push(client->queue, error);
    }
    return (item);
}

user_t *get_error_user(
    client_t *client, const char *response, server_t *server, const char *arg)
{
    user_t *item = get_user_id(server, arg);
    char *error = NULL;

    if (item == NULL) {
        asprintf(&error, response, "User doesn't exist");
        list_push(client->queue, error);
    }
    return (item);
}
