/*
** EPITECH PROJECT, 2020
** server
** File description:
** send.h
*/

#ifndef SERVER_SRC_COMMAND_SEND_H
#define SERVER_SRC_COMMAND_SEND_H

#include "client/client.h"
#include "server/server.h"

int send_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_SEND_H
