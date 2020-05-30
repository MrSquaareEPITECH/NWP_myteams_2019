/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_internal.h
*/

#ifndef SERVER_SRC_SERVER_SERVER_INTERNAL_H
#define SERVER_SRC_SERVER_SERVER_INTERNAL_H

#include "server.h"

int server_accept(server_t *server);
int server_clear(server_t *server);
int server_execute(server_t *server);

#endif // SERVER_SRC_SERVER_SERVER_INTERNAL_H
