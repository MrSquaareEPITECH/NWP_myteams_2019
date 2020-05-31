/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_H
#define NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_H

#include "def/length.h"
#include "list/list.h"

typedef struct team_s team_t;

struct team_s {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];

    list_t *channels;
    list_t *subscribers;
};

team_t *team_create(const char *name, const char *description);
bool team_get_id(team_t *team, char *uuid);
void team_delete(team_t *team);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_H
