/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_H
#define NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_H

#include "def/length.h"
#include "private/private_list.h"

typedef struct user_s user_t;

struct user_s {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];

    private_list_t *privates;
};

user_t *user_create(const char *name);
int user_compare_name(user_t *this, const char *name);
void user_delete(user_t *this);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_H