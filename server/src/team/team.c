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
    team_t *this = malloc(sizeof(team_t));

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
    this->channels = list_create();
    this->subscribers = list_create();
    return (this);
}

void team_delete(team_t *this)
{
    if (this == NULL)
        return;
    list_delete(this->channels, delete_c(channel_delete));
    list_delete(this->subscribers, delete_c(subscriber_delete));
    free(this);
}
