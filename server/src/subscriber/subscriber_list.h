/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_LIST_H

#include "subscriber.h"

typedef struct subscriber_list_s subscriber_list_t;
typedef struct subscriber_node_s subscriber_node_t;

struct subscriber_node_s {
    subscriber_t *subscriber;
    subscriber_node_t *next;
};

struct subscriber_list_s {
    subscriber_node_t *begin;
    subscriber_node_t *end;

    int (*push)(subscriber_list_t *this, subscriber_t *subscriber);
};

subscriber_list_t *subscriber_list_create(void);
void subscriber_list_delete(subscriber_list_t *subscriber_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_LIST_H
