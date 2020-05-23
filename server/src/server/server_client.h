/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_client.h
*/

#ifndef SERVER_SRC_SERVER_SERVER_CLIENT_H
#define SERVER_SRC_SERVER_SERVER_CLIENT_H

#include "client/client.h"
#include "server.h"

int server_client_add(server_t *server, client_t *client);
int server_client_receive(server_t *server, client_t *client, int *argc, char ***argv);
int server_client_send(server_t *server, client_t *client, const char *message);
int server_client_remove(server_t *server, client_t *client);
int server_client_execute(server_t *server, client_t *client);
int server_client_notify(server_t *server, client_t *client);

#endif // SERVER_SRC_SERVER_SERVER_CLIENT_H
