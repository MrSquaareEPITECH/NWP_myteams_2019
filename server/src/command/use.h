/*
** EPITECH PROJECT, 2020
** server
** File description:
** use.h
*/

#ifndef SERVER_SRC_COMMAND_USE_H
#define SERVER_SRC_COMMAND_USE_H

#include "client/client.h"
#include "server/server.h"

int use_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_USE_H
