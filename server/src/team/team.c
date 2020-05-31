/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team.c
*/

#include "team.h"

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

#include "channel/channel.h"
#include "subscriber/subscriber.h"

team_t *team_create(const char *name, const char *description)
{
    team_t *team = malloc(sizeof(team_t));

    if (team == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(team->uuid, 0, sizeof(team->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, team->uuid);
    memset(team->name, 0, sizeof(team->name));
    strncpy(team->name, name, MAX_NAME_LENGTH);
    memset(team->description, 0, sizeof(team->description));
    strncpy(team->description, description, MAX_DESCRIPTION_LENGTH);
    team->channels = list_create();
    team->subscribers = list_create();
    return (team);
}

bool team_get_id(team_t *team, char *uuid)
{
    return (strcmp(team->uuid, uuid) == 0);
}

bool team_get_name(team_t *team, char *name)
{
    return (strcmp(team->name, name) == 0);
}

void team_delete(team_t *team)
{
    if (team == NULL)
        return;
    list_delete(team->channels, delete_c(channel_delete));
    list_delete(team->subscribers, delete_c(subscriber_delete));
    free(team);
}
