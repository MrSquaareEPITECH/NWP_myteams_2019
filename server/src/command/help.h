/*
** EPITECH PROJECT, 2020
** server
** File description:
** help.h
*/

#ifndef SERVER_SRC_COMMAND_HELP_H
#define SERVER_SRC_COMMAND_HELP_H

#include "client/client.h"
#include "server/server.h"

int help_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_HELP_H
