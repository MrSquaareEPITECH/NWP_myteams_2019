/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread.c
*/

#include "thread.h"

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#include "comment/comment.h"

thread_t *thread_create(
    channel_t *parent, const char *user, const char *name, const char *body)
{
    thread_t *thread = malloc(sizeof(thread_t));

    if (thread == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(thread->uuid, 0, sizeof(thread->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, thread->uuid);
    memset(thread->user, 0, sizeof(thread->user));
    strncpy(thread->user, user, UUID_LENGTH);
    thread->timestamp = time(NULL);
    memset(thread->name, 0, sizeof(thread->name));
    strncpy(thread->name, name, MAX_NAME_LENGTH);
    memset(thread->body, 0, sizeof(thread->body));
    strncpy(thread->body, body, MAX_BODY_LENGTH);
    thread->parent = parent;
    thread->comments = list_create();
    return (thread);
}

bool thread_get_id(thread_t *thread, char *uuid)
{
    return (strcmp(thread->uuid, uuid) == 0);
}

bool thread_get_name(thread_t *thread, char *name)
{
    return (strcmp(thread->name, name) == 0);
}

void thread_delete(thread_t *thread)
{
    if (thread == NULL)
        return;
    list_delete(thread->comments, delete_c(comment_delete));
    free(thread);
}
