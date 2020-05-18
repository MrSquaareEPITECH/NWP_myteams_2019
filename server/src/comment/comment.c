/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment.c
*/

#include "comment.h"

#include <stdlib.h>
#include <string.h>

comment_t *comment_create(const char *body)
{
    comment_t *this = malloc(sizeof(comment_t));

    if (this == NULL)
        return (NULL);
    this->timestamp = time(NULL);
    memset(this->body, 0, sizeof(this->body));
    strncpy(this->body, body, MAX_BODY_LENGTH);
    return (this);
}

void comment_delete(comment_t *this)
{
    if (this == NULL)
        return;
    free(this);
}
