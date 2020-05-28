/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message.c
*/

#include "message.h"

#include <stdlib.h>
#include <string.h>

message_t *message_create(const char *user, const char *body)
{
    message_t *message = malloc(sizeof(message_t));

    if (message == NULL)
        return (NULL);
    memset(message->user, 0, sizeof(message->user));
    strncpy(message->user, user, UUID_LENGTH);
    message->timestamp = time(NULL);
    memset(message->body, 0, sizeof(message->body));
    strncpy(message->body, body, MAX_BODY_LENGTH);
    return (message);
}

void message_delete(message_t *message)
{
    if (message == NULL)
        return;
    free(message);
}
