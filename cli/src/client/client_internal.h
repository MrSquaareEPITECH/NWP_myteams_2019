/*
** EPITECH PROJECT, 2020
** cli
** File description:
** client_internal.h
*/

#ifndef CLI_SRC_CLIENT_CLIENT_INTERNAL_H
#define CLI_SRC_CLIENT_CLIENT_INTERNAL_H

#include "client.h"

int client_input(client_t *client);
int client_execute(client_t *client);
int client_notify(client_t *client);
int client_receive(client_t *client, int *argc, char ***argv);
int client_send(client_t *client, const char *message);

#endif // CLI_SRC_CLIENT_CLIENT_INTERNAL_H
