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
    private_t *private = malloc(sizeof(private_t));

    if (private == NULL)
        return (NULL);
    memset(private->uuid, 0, sizeof(private->uuid));
    strncpy(private->uuid, uuid, UUID_LENGTH);
    private->messages = list_create();
    return (private);
}

void private_delete(private_t *private)
{
    if (private == NULL)
        return;
    list_delete(private->messages, delete_c(message_delete));
    free(private);
}
