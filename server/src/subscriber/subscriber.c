/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber.c
*/

#include "subscriber.h"

#include <stdlib.h>
#include <string.h>

subscriber_t *subscriber_create(const char *uuid)
{
    subscriber_t *subscriber = malloc(sizeof(subscriber_t));

    if (subscriber == NULL)
        return (NULL);
    memset(subscriber->uuid, 0, sizeof(subscriber->uuid));
    strncpy(subscriber->uuid, uuid, UUID_LENGTH);
    return (subscriber);
}

void subscriber_delete(subscriber_t *subscriber)
{
    if (subscriber == NULL)
        return;
    free(subscriber);
}
