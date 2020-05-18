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

#include "private/private.h"

user_t *user_create(const char *name)
{
    user_t *this = malloc(sizeof(user_t));

    if (this == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(this->uuid, 0, sizeof(this->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, this->uuid);
    memset(this->name, 0, sizeof(this->name));
    strncpy(this->name, name, MAX_NAME_LENGTH);
    this->privates = list_create();
    return (this);
}

void user_delete(user_t *this)
{
    if (this == NULL)
        return;
    list_delete(this->privates, delete_c(private_delete));
    free(this);
}
