/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** exchange.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_EXCHANGE_EXCHANGE_H
#define NWP_MYTEAMS_2019_SERVER_SRC_EXCHANGE_EXCHANGE_H

#include "def/length.h"
#include "list/list.h"

typedef struct exchange_s exchange_t;

struct exchange_s {
    char uuid[UUID_LENGTH + 1];

    list_t *messages;
};

exchange_t *exchange_create(void);
void exchange_delete(exchange_t *exchange);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_EXCHANGE_EXCHANGE_H
