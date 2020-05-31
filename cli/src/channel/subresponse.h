/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_CHANNEL_SUBRESPONSE_H
#define CLI_SRC_CHANNEL_SUBRESPONSE_H

#include <stddef.h>

#include "def/response.h"

int channel_create_subresponse(client_t *client, int argc, char **argv);
int channel_created_subresponse(client_t *client, int argc, char **argv);
int channel_info_subresponse(client_t *client, int argc, char **argv);
int channel_list_subresponse(client_t *client, int argc, char **argv);
int channel_use_subresponse(client_t *client, int argc, char **argv);

static const response_t CHANNEL_SUBRESPONSES[] = {
    {"CREATE", channel_create_subresponse}, {"INFO", channel_info_subresponse},
    {"LIST", channel_list_subresponse}, {"USE", channel_use_subresponse},
    {"CREATED", channel_created_subresponse}, {NULL, NULL}};

#endif // CLI_SRC_CHANNEL_SUBRESPONSE_H
