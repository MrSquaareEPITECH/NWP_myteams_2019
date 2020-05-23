/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_internal.h
*/

#ifndef SERVER_SRC_COMMAND_LIST_INTERNAL_H
#define SERVER_SRC_COMMAND_LIST_INTERNAL_H

#include "client/client.h"
#include "server/server.h"

int list_channel(server_t *server, client_t *client, int argc, char **argv);
int list_comment(server_t *server, client_t *client, int argc, char **argv);
int list_team(server_t *server, client_t *client, int argc, char **argv);
int list_thread(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_LIST_INTERNAL_H
