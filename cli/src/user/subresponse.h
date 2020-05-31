/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_USER_SUBRESPONSE_H
#define CLI_SRC_USER_SUBRESPONSE_H

#include <stddef.h>

#include "def/response.h"

int user_info_subresponse(client_t *client, int argc, char **argv);
int user_list_subresponse(client_t *client, int argc, char **argv);
int user_login_subresponse(client_t *client, int argc, char **argv);
int user_logout_subresponse(client_t *client, int argc, char **argv);
int user_loggedin_subresponse(client_t *client, int argc, char **argv);
int user_loggedout_subresponse(client_t *client, int argc, char **argv);
int user_subscribe_subresponse(client_t *client, int argc, char **argv);
int user_unsubscribe_subresponse(client_t *client, int argc, char **argv);

static const response_t USER_SUBRESPONSES[] = {{"INFO", user_info_subresponse},
    {"LIST", user_list_subresponse}, {"LOGIN", user_login_subresponse},
    {"LOGOUT", user_logout_subresponse},
    {"SUBSCRIBE", user_subscribe_subresponse},
    {"UNSUBSCRIBE", user_unsubscribe_subresponse},
    {"LOGGEDIN", user_loggedin_subresponse},
    {"LOGGEDOUT", user_loggedout_subresponse}, {NULL, NULL}};

#endif // CLI_SRC_USER_SUBRESPONSE_H
