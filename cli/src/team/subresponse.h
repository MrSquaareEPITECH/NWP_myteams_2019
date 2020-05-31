/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_TEAM_SUBRESPONSE_H
#define CLI_SRC_TEAM_SUBRESPONSE_H

#include <stddef.h>

#include "def/response.h"

int team_create_subresponse(client_t *client, int argc, char **argv);
int team_created_subresponse(client_t *client, int argc, char **argv);
int team_info_subresponse(client_t *client, int argc, char **argv);
int team_list_subresponse(client_t *client, int argc, char **argv);
int team_use_subresponse(client_t *client, int argc, char **argv);

static const response_t TEAM_SUBRESPONSES[] = {
    {"CREATE", team_create_subresponse}, {"INFO", team_info_subresponse},
    {"LIST", team_list_subresponse}, {"USE", team_use_subresponse},
    {"CREATED", team_created_subresponse}, {NULL, NULL}};

#endif // CLI_SRC_TEAM_SUBRESPONSE_H
