/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscribed_internal.h
*/

#ifndef SERVER_SRC_COMMAND_SUBSCRIBED_INTERNAL_H
#define SERVER_SRC_COMMAND_SUBSCRIBED_INTERNAL_H

#include "client/client.h"
#include "server/server.h"

int subscribed_team(server_t *server, client_t *client, int argc, char **argv);
int subscribed_user(server_t *server, client_t *client, int argc, char **argv);

#endif // SERVER_SRC_COMMAND_SUBSCRIBED_INTERNAL_H
