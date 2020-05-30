/*
** EPITECH PROJECT, 2020
** server
** File description:
** user.h
*/

#ifndef SERVER_SRC_COMMAND_USER_H
#define SERVER_SRC_COMMAND_USER_H

#include "client/client.h"
#include "server/server.h"

int user_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_USER_H
