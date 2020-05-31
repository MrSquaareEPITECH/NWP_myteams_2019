/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_GLOBAL_SUBRESPONSE_H
#define CLI_SRC_GLOBAL_SUBRESPONSE_H

#include "def/response.h"

int global_create_subresponse(client_t *client, int argc, char **argv);
int global_info_subresponse(client_t *client, int argc, char **argv);
int global_list_subresponse(client_t *client, int argc, char **argv);
int global_subscribed_subresponse(client_t *client, int argc, char **argv);

static const response_t GLOBAL_SUBRESPONSES[] = {
    {"CREATE", global_create_subresponse}, {"INFO", global_info_subresponse},
    {"LIST", global_list_subresponse},
    {"SUBSCRIBER", global_subscribed_subresponse}, {NULL, NULL}};

#endif // CLI_SRC_GLOBAL_SUBRESPONSE_H
