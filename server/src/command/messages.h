/*
** EPITECH PROJECT, 2020
** server
** File description:
** messages.h
*/

#ifndef SERVER_SRC_COMMAND_MESSAGES_H
#define SERVER_SRC_COMMAND_MESSAGES_H

#include "client/client.h"
#include "server/server.h"

int messages_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_MESSAGES_H
