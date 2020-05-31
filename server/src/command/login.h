/*
** EPITECH PROJECT, 2020
** server
** File description:
** login.h
*/

#ifndef SERVER_SRC_COMMAND_LOGIN_H
#define SERVER_SRC_COMMAND_LOGIN_H

#include "client/client.h"
#include "server/server.h"

int login_command(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_LOGIN_H
