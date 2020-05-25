/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment.c
*/

#include "comment.h"

#include <stdlib.h>
#include <string.h>

comment_t *comment_create(thread_t *thread, const char *body)
{
    comment_t *comment = malloc(sizeof(comment_t));

    if (comment == NULL)
        return (NULL);
    comment->timestamp = time(NULL);
    memset(comment->body, 0, sizeof(comment->body));
    strncpy(comment->body, body, MAX_BODY_LENGTH);
    comment->thread = thread;
    return (comment);
}

void comment_delete(comment_t *comment)
{
    if (comment == NULL)
        return;
    free(comment);
}