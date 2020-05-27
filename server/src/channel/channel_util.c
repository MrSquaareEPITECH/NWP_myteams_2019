/*
** EPITECH PROJECT, 2020
** server
** File description:
** channel_util.c
*/

#include "channel_util.h"

#include <stdlib.h>
#include <stringext.h>

#include "def/data.h"
#include "util/string.h"

char *channel_to_data(channel_t *channel)
{
    char *data = strfmt(
        DATA_CHANNEL, channel->uuid, channel->name, channel->description);

    return (data);
}

thread_t *channel_get_thread(channel_t *channel, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    thread_t *thread =
        list_get(channel->threads, id, (compare_t)(thread_get_id));

    free(id);
    return (thread);
}
