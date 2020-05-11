/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_LIST_H

#include "team.h"

typedef struct team_list_s team_list_t;
typedef struct team_node_s team_node_t;

struct team_node_s {
    team_t *team;
    team_node_t *next;
};

struct team_list_s {
    team_node_t *begin;
    team_node_t *end;

    team_t *(*get)(team_list_t *this, const char *uuid);
    int (*push)(team_list_t *this, team_t *team);
};

team_list_t *team_list_create(void);
void team_list_delete(team_list_t *team_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_LIST_H
