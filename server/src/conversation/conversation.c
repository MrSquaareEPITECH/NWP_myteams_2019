/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** conversation.c
*/

#include "conversation.h"

#include <stdlib.h>
#include <string.h>

#include "message/message.h"
#include "subscriber/subscriber.h"

conversation_t *conversation_create(const char *uuid)
{
    conversation_t *priv = malloc(sizeof(conversation_t));

    if (priv == NULL)
        return (NULL);
    memset(priv->uuid, 0, sizeof(priv->uuid));
    strncpy(priv->uuid, uuid, UUID_LENGTH);
    priv->subscribers = list_create();
    priv->messages = list_create();
    return (priv);
}

void conversation_delete(conversation_t *priv)
{
    if (priv == NULL)
        return;
    list_delete(priv->subscribers, delete_c(subscriber_delete));
    list_delete(priv->messages, delete_c(message_delete));
    free(priv);
}
