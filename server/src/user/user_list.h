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

struct user_list_s {
    user_t *user;
    user_list_t *next;
};

#endif // NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_LIST_H
