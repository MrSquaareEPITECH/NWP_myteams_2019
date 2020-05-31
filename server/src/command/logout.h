/*
** EPITECH PROJECT, 2020
** server
** File description:
** logout.h
*/

#ifndef SERVER_SRC_COMMAND_LOGOUT_H
#define SERVER_SRC_COMMAND_LOGOUT_H

#include "client/client.h"
#include "server/server.h"

int logout_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_LOGOUT_H
