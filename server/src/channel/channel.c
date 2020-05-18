/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel.c
*/

#include "channel.h"

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#include "thread/thread.h"

channel_t *channel_create(const char *name, const char *description)
{
    channel_t *this = malloc(sizeof(channel_t));

    if (this == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(this->uuid, 0, sizeof(this->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, this->uuid);
    memset(this->name, 0, sizeof(this->name));
    strncpy(this->name, name, MAX_NAME_LENGTH);
    memset(this->description, 0, sizeof(this->description));
    strncpy(this->description, description, MAX_DESCRIPTION_LENGTH);
    this->threads = list_create();
    return (this);
}

void channel_delete(channel_t *this)
{
    if (this == NULL)
        return;
    list_delete(this->threads, delete_c(thread_delete));
    free(this);
}
