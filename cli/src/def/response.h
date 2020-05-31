/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_DEF_RESPONSE_H
#define CLI_SRC_DEF_RESPONSE_H

#include <stddef.h>

#include "client/client.h"

typedef struct response_s response_t;

struct response_s {
    const char *name;
    int (*func)(client_t *client, int argc, char **argv);
};

int global_response(client_t *client, int argc, char **argv);
int channel_response(client_t *client, int argc, char **argv);
int comment_response(client_t *client, int argc, char **argv);
int message_response(client_t *client, int argc, char **argv);
int team_response(client_t *client, int argc, char **argv);
int thread_response(client_t *client, int argc, char **argv);
int user_response(client_t *client, int argc, char **argv);

static const response_t RESPONSES[] = {{"GLOBAL", global_response},
    {"CHANNEL", channel_response}, {"COMMENT", comment_response},
    {"MESSAGE", message_response}, {"TEAM", team_response},
    {"THREAD", thread_response}, {"USER", user_response}, {NULL, NULL}};

#endif // CLI_SRC_DEF_RESPONSE_H
