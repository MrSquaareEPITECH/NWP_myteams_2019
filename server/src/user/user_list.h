/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_LIST_H

#include "user.h"

typedef struct user_list_s user_list_t;
typedef struct user_node_s user_node_t;

struct user_node_s {
    user_t *user;
    user_node_t *next;
};

struct user_list_s {
    user_node_t *begin;
    user_node_t *end;

    user_t *(*get)(user_list_t *this, const char *uuid);
    int (*push)(user_list_t *this, user_t *user);
};

user_list_t *user_list_create(void);
void user_list_delete(user_list_t *user_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_LIST_H
