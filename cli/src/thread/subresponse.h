/*
** EPITECH PROJECT, 2020
** cli
** File description:
** response.h
*/

#ifndef CLI_SRC_THREAD_SUBRESPONSE_H
#define CLI_SRC_THREAD_SUBRESPONSE_H

#include <stddef.h>

#include "def/response.h"

int thread_create_subresponse(client_t *client, int argc, char **argv);
int thread_created_subresponse(client_t *client, int argc, char **argv);
int thread_info_subresponse(client_t *client, int argc, char **argv);
int thread_list_subresponse(client_t *client, int argc, char **argv);
int thread_use_subresponse(client_t *client, int argc, char **argv);

static const response_t THREAD_SUBRESPONSES[] = {
    {"CREATE", thread_create_subresponse}, {"INFO", thread_info_subresponse},
    {"LIST", thread_list_subresponse}, {"USE", thread_use_subresponse},
    {"CREATED", thread_created_subresponse}, {NULL, NULL}};

#endif // CLI_SRC_THREAD_SUBRESPONSE_H
