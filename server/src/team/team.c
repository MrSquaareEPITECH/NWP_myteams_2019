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

    this->channels = channel_list_create();
    this->subscribers = subscriber_list_create();

    return (this);
}

void team_delete(team_t *this)
{
    if (this == NULL)
        return;

    channel_list_delete(this->channels);
    subscriber_list_delete(this->subscribers);

    free(this);
}
