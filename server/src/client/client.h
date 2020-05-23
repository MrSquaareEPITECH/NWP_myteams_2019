/*
** EPITECH PROJECT, 2020
** server
** File description:
** client.h
*/

#ifndef SERVER_SRC_CLIENT_CLIENT_H
#define SERVER_SRC_CLIENT_CLIENT_H

#include <socket.h>

#include "list/list.h"
#include "user/user.h"

enum client_state { CLIENT_UNKNOWN, CLIENT_CONNECTED, CLIENT_LOGGED, CLIENT_DISCONNECTED };

typedef struct client_s client_t;

#define client_c(ptr) ((client_t *)(ptr))

struct client_s {
    socket_t *sock;
    list_t *queue;
    enum client_state state;

    user_t *user;
};

client_t *client_create(void);
void client_delete(client_t *client);

#endif // SERVER_SRC_CLIENT_CLIENT_H
