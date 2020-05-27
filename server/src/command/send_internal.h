/*
** EPITECH PROJECT, 2020
** server
** File description:
** send_internal.h
*/

#ifndef SERVER_SRC_COMMAND_SEND_INTERNAL_H
#define SERVER_SRC_COMMAND_SEND_INTERNAL_H

#include "client/client.h"
#include "exchange/exchange.h"
#include "message/message.h"
#include "server/server.h"

exchange_t *get_exchange(server_t *server, user_t *user1, user_t *user2);
exchange_t *create_exchange(server_t *server, user_t *user1, user_t *user2);
message_t *create_message(char **argv);

#endif // SERVER_SRC_COMMAND_SEND_INTERNAL_H
