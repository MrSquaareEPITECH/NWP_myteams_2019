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
    subscriber_t *this = malloc(sizeof(subscriber_t));

    if (this == NULL)
        return (NULL);
    memset(this->uuid, 0, sizeof(this->uuid));
    strncpy(this->uuid, uuid, UUID_LENGTH);
    return (this);
}

void subscriber_delete(subscriber_t *subscriber)
{
    if (subscriber == NULL)
        return;
    free(subscriber);
}
