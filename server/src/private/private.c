/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private.c
*/

#include "private.h"

#include <stdlib.h>
#include <string.h>

#include "message/message.h"

private_t *private_create(const char *uuid)
{
    private_t *priv = malloc(sizeof(private_t));

    if (priv == NULL)
        return (NULL);
    memset(priv->uuid, 0, sizeof(priv->uuid));
    strncpy(priv->uuid, uuid, UUID_LENGTH);
    priv->messages = list_create();
    return (priv);
}

void private_delete(private_t *priv)
{
    if (priv == NULL)
        return;
    list_delete(priv->messages, delete_c(message_delete));
    free(priv);
}
