/*
** EPITECH PROJECT, 2020
** server
** File description:
** send_internal.c
*/

#include "command/send_internal.h"

#include <stdlib.h>
#include <stringext.h>

#include "private/private.h"
#include "server/server_util.h"
#include "user/user_util.h"

exchange_t *get_exchange(server_t *server, user_t *user1, user_t *user2)
{
    private_t *priv = user_get_private(user1, user2->uuid);
    exchange_t *exchange = NULL;

    if (priv)
        exchange = server_get_exchange(server, priv->exchange);
    return (exchange);
}

exchange_t *create_exchange(server_t *server, user_t *user1, user_t *user2)
{
    exchange_t *exchange = exchange_create();
    private_t *priv1 = private_create(user2->uuid, exchange->uuid);
    private_t *priv2 = private_create(user1->uuid, exchange->uuid);

    list_push(user1->privates, priv1);
    list_push(user2->privates, priv2);
    list_push(server->exchanges, exchange);
    return (exchange);
}

message_t *create_message(const char *user, char **argv)
{
    char *body = strtrim(argv[2], " \t\"");
    message_t *message = message_create(user, body);

    free(body);
    return (message);
}
