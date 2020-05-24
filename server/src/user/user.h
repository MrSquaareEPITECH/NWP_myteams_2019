/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_H
#define NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_H

#include "def/length.h"
#include "list/list.h"

enum USE {
    USE_CHANNEL,
    USE_SERVER,
    USE_TEAM,
    USE_THREAD
};

typedef struct user_s user_t;

struct user_s {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];

    list_t *privates;

    enum USE use;
    void *obj;
};

user_t *user_create(const char *name);
bool user_get_id(user_t *user, char *uuid);
void user_delete(user_t *user);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_H
