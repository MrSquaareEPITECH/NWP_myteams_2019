/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.c
*/

#include "user.h"

#include <stdlib.h>
#include <string.h>

user_t *user_create(const char *name)
{
    user_t *this = malloc(sizeof(user_t));

    if (this == NULL)
        return (NULL);

    memset(this->name, 0, MAX_NAME_LENGTH);
    strncpy(this->name, name, MAX_NAME_LENGTH - 1);

    this->privates = NULL;

    return (this);
}

void user_delete(user_t *this)
{
    if (this == NULL)
        return;

    private_list_delete(this->privates);

    free(this);
}
