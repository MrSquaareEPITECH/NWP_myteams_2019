/*
** EPITECH PROJECT, 2020
** server
** File description:
** create.h
*/

#ifndef SERVER_SRC_COMMAND_CREATE_H
#define SERVER_SRC_COMMAND_CREATE_H

#include "client/client.h"
#include "server/server.h"

int create_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_CREATE_H
