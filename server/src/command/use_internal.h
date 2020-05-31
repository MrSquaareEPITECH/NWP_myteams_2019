/*
** EPITECH PROJECT, 2020
** server
** File description:
** use_internal.h
*/

#ifndef SERVER_SRC_COMMAND_USE_INTERNAL_H
#define SERVER_SRC_COMMAND_USE_INTERNAL_H

#include "client/client.h"
#include "server/server.h"

int use_channel(server_t *server, client_t *client, int argc, char **argv);
int use_server(server_t *server, client_t *client, int argc, char **argv);
int use_team(server_t *server, client_t *client, int argc, char **argv);
int use_thread(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_USE_INTERNAL_H
