/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** exchange.c
*/

#include "exchange.h"

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#include "message/message.h"
#include "subscriber/subscriber.h"

exchange_t *exchange_create(void)
{
    exchange_t *exchange = malloc(sizeof(exchange_t));

    if (exchange == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(exchange->uuid, 0, sizeof(exchange->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, exchange->uuid);
    exchange->messages = list_create();
    return (exchange);
}

bool exchange_get_id(exchange_t *exchange, const char *uuid)
{
    return (strcmp(exchange->uuid, uuid) == 0);
}

void exchange_delete(exchange_t *exchange)
{
    if (exchange == NULL)
        return;
    list_delete(exchange->messages, delete_c(message_delete));
    free(exchange);
}
