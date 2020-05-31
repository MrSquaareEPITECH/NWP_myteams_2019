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

private_t *private_create(const char *uuid, const char *exchange)
{
    private_t *priv = malloc(sizeof(private_t));

    if (priv == NULL)
        return (NULL);
    memset(priv->uuid, 0, sizeof(priv->uuid));
    strncpy(priv->uuid, uuid, UUID_LENGTH);
    memset(priv->exchange, 0, sizeof(priv->exchange));
    strncpy(priv->exchange, exchange, UUID_LENGTH);
    return (priv);
}

bool private_get_id(private_t *priv, const char *uuid)
{
    return (strcmp(priv->uuid, uuid) == 0);
}

void private_delete(private_t *priv)
{
    if (priv == NULL)
        return;
    free(priv);
}
