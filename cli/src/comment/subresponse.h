/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_COMMENT_SUBRESPONSE_H
#define CLI_SRC_COMMENT_SUBRESPONSE_H

#include "def/response.h"

int comment_create_subresponse(client_t *client, int argc, char **argv);
int comment_created_subresponse(client_t *client, int argc, char **argv);
int comment_list_subresponse(client_t *client, int argc, char **argv);

static const response_t COMMENT_SUBRESPONSES[] = {
    {"CREATE", comment_create_subresponse}, {"LIST", comment_list_subresponse},
    {"CREATED", comment_created_subresponse}, {NULL, NULL}};

#endif // CLI_SRC_COMMENT_SUBRESPONSE_H
