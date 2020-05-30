/*
** EPITECH PROJECT, 2020
** server
** File description:
** info.h
*/

#ifndef SERVER_SRC_COMMAND_INFO_H
#define SERVER_SRC_COMMAND_INFO_H

#include "client/client.h"
#include "server/server.h"

int info_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_INFO_H
