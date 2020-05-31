/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_MESSAGE_SUBRESPONSE_H
#define CLI_SRC_MESSAGE_SUBRESPONSE_H

#include <stddef.h>

#include "def/response.h"

int message_create_subresponse(client_t *client, int argc, char **argv);
int message_created_subresponse(client_t *client, int argc, char **argv);
int message_list_subresponse(client_t *client, int argc, char **argv);

static const response_t MESSAGE_SUBRESPONSES[] = {
    {"LIST", message_list_subresponse}, {"SEND", message_create_subresponse},
    {"CREATED", message_created_subresponse}, {NULL, NULL}};

#endif // CLI_SRC_MESSAGE_SUBRESPONSE_H
