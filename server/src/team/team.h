/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_H
#define NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_H

#include "channel/channel_list.h"
#include "def/length.h"
#include "user/user_list.h"

typedef struct team_s team_t;

struct team_s {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];

    channel_list_t *channels;
    user_list_t *users;
};

team_t *team_create(const char *name, const char *description);
void team_delete(team_t *this);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_H
