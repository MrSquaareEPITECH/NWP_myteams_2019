/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** conversation.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_CONVERSATION_CONVERSATION_H
#define NWP_MYTEAMS_2019_SERVER_SRC_CONVERSATION_CONVERSATION_H

#include "def/length.h"
#include "list/list.h"

typedef struct conversation_s conversation_t;

struct conversation_s {
    char uuid[UUID_LENGTH + 1];

    list_t *subscribers;
    list_t *messages;
};

conversation_t *conversation_create(void);
bool conversation_get_id(conversation_t *conversation, const char *uuid);
void conversation_delete(conversation_t *priv);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_CONVERSATION_CONVERSATION_H
