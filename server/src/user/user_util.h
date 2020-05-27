/*
** EPITECH PROJECT, 2020
** server
** File description:
** user_util.h
*/

#ifndef SERVER_SRC_USER_USER_UTIL_H
#define SERVER_SRC_USER_USER_UTIL_H

#include "private/private.h"
#include "user.h"

char *user_to_data(user_t *user);
private_t *user_get_private(user_t *user, const char *uuid);

#endif // SERVER_SRC_USER_USER_UTIL_H
