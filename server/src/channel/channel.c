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

channel_t *channel_create(
    team_t *parent, const char *name, const char *description)
{
    channel_t *channel = malloc(sizeof(channel_t));

    if (channel == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(channel->uuid, 0, sizeof(channel->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, channel->uuid);
    memset(channel->name, 0, sizeof(channel->name));
    strncpy(channel->name, name, MAX_NAME_LENGTH);
    memset(channel->description, 0, sizeof(channel->description));
    strncpy(channel->description, description, MAX_DESCRIPTION_LENGTH);
    channel->parent = parent;
    channel->threads = list_create();
    return (channel);
}

void channel_delete(channel_t *channel)
{
    if (channel == NULL)
        return;
    list_delete(channel->threads, delete_c(thread_delete));
    free(channel);
}
