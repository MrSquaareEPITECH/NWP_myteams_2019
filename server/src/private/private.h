/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_H
#define NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_H

#include "def/length.h"
#include "list/list.h"

typedef struct private_s private_t;

struct private_s {
    char uuid[UUID_LENGTH + 1];
    char exchange[UUID_LENGTH + 1];
};

private_t *private_create(const char *uuid, const char *user);
bool private_get_id(private_t *priv, const char *uuid);
void private_delete(private_t *priv);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_H
