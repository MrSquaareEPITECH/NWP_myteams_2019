/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_internal.h
*/

#ifndef SERVER_SRC_COMMAND_INFO_INTERNAL_H
#define SERVER_SRC_COMMAND_INFO_INTERNAL_H

#include "client/client.h"
#include "server/server.h"

int info_channel(server_t *server, client_t *client, int argc, char **argv);
int info_team(server_t *server, client_t *client, int argc, char **argv);
int info_thread(server_t *server, client_t *client, int argc, char **argv);
int info_user(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_INFO_INTERNAL_H
