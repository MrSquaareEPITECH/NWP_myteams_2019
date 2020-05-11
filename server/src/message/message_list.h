/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_LIST_H

#include "message.h"

typedef struct message_list_s message_list_t;
typedef struct message_node_s message_node_t;

struct message_node_s {
    message_t *message;
    message_node_t *next;
};

struct message_list_s {
    message_node_t *begin;
    message_node_t *end;

    int (*push)(message_list_t *this, message_t *message);
};

message_list_t *message_list_create(void);
void message_list_delete(message_list_t *message_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_LIST_H
