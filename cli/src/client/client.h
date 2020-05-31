/*
** EPITECH PROJECT, 2020
** cli
** File description:
** client.h
*/

#ifndef CLI_SRC_CLIENT_CLIENT_H
#define CLI_SRC_CLIENT_CLIENT_H

#include <select.h>
#include <socket.h>

#include "list/list.h"

enum client_state { CLIENT_UNKNOWN, CLIENT_CONNECTED, CLIENT_DISCONNECTED };

typedef struct client_s client_t;

struct client_s {
    socket_t input;
    socket_t *sock;
    select_t *sel;
    list_t *queue;
    enum client_state state;
};

client_t *client_create(const char *ip, uint16_t port);
int client_init(client_t *client);
int client_run(client_t *client);
void client_delete(client_t *client);

#endif // CLI_SRC_CLIENT_CLIENT_H
