/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_LIST_H

#include "channel.h"

typedef struct channel_list_s channel_list_t;
typedef struct channel_node_s channel_node_t;

struct channel_node_s {
    channel_t *channel;
    channel_node_t *next;
};

struct channel_list_s {
    channel_node_t *begin;
    channel_node_t *end;

    channel_t *(*get)(channel_list_t *this, const char *uuid);
    int (*push)(channel_list_t *this, channel_t *channel);
};

channel_list_t *channel_list_create(void);
void channel_list_delete(channel_list_t *this);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_LIST_H
