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
    private_t *this = malloc(sizeof(private_t));

    if (this == NULL)
        return (NULL);
    memset(this->uuid, 0, sizeof(this->uuid));
    strncpy(this->uuid, uuid, UUID_LENGTH);
    this->messages = list_create();
    return (this);
}

void private_delete(private_t *this)
{
    if (this == NULL)
        return;
    list_delete(this->messages, delete_c(message_delete));
    free(this);
}
