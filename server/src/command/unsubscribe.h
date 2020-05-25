/*
** EPITECH PROJECT, 2020
** server
** File description:
** unsubscribe.h
*/

#ifndef SERVER_SRC_COMMAND_UNSUBSCRIBE_H
#define SERVER_SRC_COMMAND_UNSUBSCRIBE_H

#include "client/client.h"
#include "server/server.h"

int unsubscribe_command(
    server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_UNSUBSCRIBE_H
