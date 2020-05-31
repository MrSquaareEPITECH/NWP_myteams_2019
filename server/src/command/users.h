/*
** EPITECH PROJECT, 2020
** server
** File description:
** users.h
*/

#ifndef SERVER_SRC_COMMAND_USERS_H
#define SERVER_SRC_COMMAND_USERS_H

#include "client/client.h"
#include "server/server.h"

int users_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_USERS_H
