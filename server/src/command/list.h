/*
** EPITECH PROJECT, 2020
** server
** File description:
** list.h
*/

#ifndef SERVER_SRC_COMMAND_LIST_H
#define SERVER_SRC_COMMAND_LIST_H

#include "client/client.h"
#include "server/server.h"

int list_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_LIST_H
