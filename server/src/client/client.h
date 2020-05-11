/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_CLIENT_CLIENT_H
#define NWP_MYTEAMS_2019_SERVER_SRC_CLIENT_CLIENT_H

#include "user/user.h"

typedef struct client_s client_t;

struct client_s {
    user_t *user;
};

client_t *client_create(void);
void client_delete(client_t *this);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_CLIENT_CLIENT_H
