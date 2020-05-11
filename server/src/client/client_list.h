/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_CLIENT_CLIENT_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_CLIENT_CLIENT_LIST_H

#include "client.h"

typedef struct client_list_s client_list_t;
typedef struct client_node_s client_node_t;

struct client_node_s {
    client_t *client;
    client_node_t *next;
};

struct client_list_s {
    client_node_t *begin;
    client_node_t *end;

    int (*push)(client_list_t *this, client_t *client);
};

client_list_t *client_list_create(void);
void client_list_delete(client_list_t *this);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_CLIENT_CLIENT_LIST_H
