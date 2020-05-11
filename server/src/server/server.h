/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_SERVER_SERVER_H
#define NWP_MYTEAMS_2019_SERVER_SRC_SERVER_SERVER_H

#include "client/client_list.h"
#include "team/team_list.h"

typedef struct server_s server_t;

struct server_s {
    client_list_t *clients;
    team_list_t *teams;
};

server_t *server_create(void);
void server_delete(server_t *this);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_SERVER_SERVER_H
