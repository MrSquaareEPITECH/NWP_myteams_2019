/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message.c
*/

#include "message.h"

#include <stdlib.h>
#include <string.h>

message_t *message_create(const char *body)
{
    message_t *this = malloc(sizeof(message_t));

    if (this == NULL)
        return (NULL);

    this->timestamp = time(NULL);
    memset(this->body, 0, sizeof(this->body));
    strncpy(this->body, body, MAX_BODY_LENGTH);

    return (this);
}

void message_delete(message_t *this)
{
    if (this == NULL)
        return;

    free(this);
}
