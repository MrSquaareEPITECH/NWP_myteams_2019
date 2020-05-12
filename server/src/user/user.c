/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user.c
*/

#include "user.h"

#include <stdlib.h>
#include <string.h>
#include <uuid/uuid.h>

user_t *user_create(const char *name)
{
    user_t *this = malloc(sizeof(user_t));

    if (this == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(this->uuid, 0, sizeof(this->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, this->uuid);
    memset(this->name, 0, MAX_NAME_LENGTH);
    strncpy(this->name, name, MAX_NAME_LENGTH - 1);

    this->privates = private_list_create();

    return (this);
}

int user_compare_name(user_t *this, const char *name)
{
    return (strcmp(this->name, name) == 0);
}

void user_delete(user_t *this)
{
    if (this == NULL)
        return;

    private_list_delete(this->privates);

    free(this);
}
