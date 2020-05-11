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

thread_t *thread_create(const char *name, const char *description)
{
    thread_t *this = malloc(sizeof(thread_t));

    if (this == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(this->uuid, 0, sizeof(this->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, this->uuid);
    this->timestamp = time(NULL);
    memset(this->name, 0, MAX_NAME_LENGTH);
    strncpy(this->name, name, MAX_NAME_LENGTH - 1);
    memset(this->description, 0, MAX_DESCRIPTION_LENGTH);
    strncpy(this->description, description, MAX_DESCRIPTION_LENGTH - 1);

    this->comments = comment_list_create();

    return (this);
}

void thread_delete(thread_t *this)
{
    if (this == NULL)
        return;

    comment_list_delete(this->comments);

    free(this);
}
