/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribe.h
*/

#ifndef SERVER_SRC_COMMAND_SUBSCRIBE_H
#define SERVER_SRC_COMMAND_SUBSCRIBE_H

#include "client/client.h"
#include "server/server.h"

int subscribe_command(
    server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_SUBSCRIBE_H
