/*
** EPITECH PROJECT, 2020
** server
** File description:
** server.h
*/

#ifndef SERVER_SRC_SERVER_SERVER_H
#define SERVER_SRC_SERVER_SERVER_H

#include <select.h>
#include <socket.h>

#include "list/list.h"

typedef struct server_s server_t;

struct server_s {
    timeval_t *timeval;
    socket_t *sock;
    select_t *sel;

    list_t *clients;

    list_t *teams;
    list_t *exchanges;
    list_t *users;
};

server_t *server_create(uint16_t port);
int server_init(server_t *server);
int server_run(server_t *server);
void server_delete(server_t *server);

#endif // SERVER_SRC_SERVER_SERVER_H
