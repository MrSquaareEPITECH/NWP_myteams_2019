/*
** EPITECH PROJECT, 2020
** server
** File description:
** create_internal.h
*/

#ifndef SERVER_SRC_COMMAND_CREATE_INTERNAL_H
#define SERVER_SRC_COMMAND_CREATE_INTERNAL_H

#include "client/client.h"
#include "server/server.h"

int create_channel(server_t *server, client_t *client, int argc, char **argv);
int create_comment(server_t *server, client_t *client, int argc, char **argv);
int create_team(server_t *server, client_t *client, int argc, char **argv);
int create_thread(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_CREATE_INTERNAL_H
