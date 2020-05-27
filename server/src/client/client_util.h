/*
** EPITECH PROJECT, 2020
** server
** File description:
** client_util.h
*/

#ifndef SERVER_SRC_CLIENT_CLIENT_UTIL_H
#define SERVER_SRC_CLIENT_CLIENT_UTIL_H

#include "client.h"
#include "def/code.h"

typedef char *(*to_data_t)(void *obj);

typedef struct reply_list_s {
    const char *message;
    const char *start;
    const char *end;
} reply_list_t;

int client_reply(client_t *client, char *message, char *data);
int client_reply_list(
    client_t *client, reply_list_t *options, list_t *list, to_data_t to_data);

#endif // SERVER_SRC_CLIENT_CLIENT_UTIL_H
