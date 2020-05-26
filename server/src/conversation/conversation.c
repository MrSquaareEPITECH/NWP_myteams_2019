/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** conversation.c
*/

#include "conversation.h"

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#include "message/message.h"
#include "subscriber/subscriber.h"

conversation_t *conversation_create()
{
    conversation_t *conversation = malloc(sizeof(conversation_t));

    if (conversation == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(conversation->uuid, 0, sizeof(conversation->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, conversation->uuid);
    conversation->subscribers = list_create();
    conversation->messages = list_create();
    return (conversation);
}

bool conversation_get_id(conversation_t *conversation, const char *uuid)
{
    return (strcmp(conversation->uuid, uuid) == 0);
}

void conversation_delete(conversation_t *priv)
{
    if (priv == NULL)
        return;
    list_delete(priv->subscribers, delete_c(subscriber_delete));
    list_delete(priv->messages, delete_c(message_delete));
    free(priv);
}
