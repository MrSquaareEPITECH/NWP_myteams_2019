/*
** EPITECH PROJECT, 2020
** server
** File description:
** team_util.c
*/
#include "team_util.h"

#include <stdlib.h>
#include <stringext.h>

#include "def/data.h"
#include "util/string.h"

char *team_to_data(team_t *team)
{
    char *data = strfmt(DATA_TEAM, team->uuid, team->name, team->description);

    return (data);
}

channel_t *team_get_channel(team_t *team, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    channel_t *channel =
        list_get(team->channels, id, (compare_t)(channel_get_id));

    free(id);
    return (channel);
}

subscriber_t *team_get_subscriber(team_t *team, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    subscriber_t *subscriber =
        list_get(team->subscribers, id, (compare_t)(subscriber_get_id));

    free(id);
    return (subscriber);
}
