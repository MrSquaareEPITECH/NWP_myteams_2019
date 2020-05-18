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

thread_t *thread_create(const char *name, const char *body)
{
    thread_t *this = malloc(sizeof(thread_t));

    if (this == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(this->uuid, 0, sizeof(this->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, this->uuid);
    this->timestamp = time(NULL);
    memset(this->name, 0, sizeof(this->name));
    strncpy(this->name, name, MAX_NAME_LENGTH);
    memset(this->body, 0, sizeof(this->body));
    strncpy(this->body, body, MAX_BODY_LENGTH);
    this->comments = list_create();
    return (this);
}

void thread_delete(thread_t *this)
{
    if (this == NULL)
        return;
    list_delete(this->comments, delete_c(comment_delete));
    free(this);
}
