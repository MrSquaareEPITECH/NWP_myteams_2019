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
    user_t *user = malloc(sizeof(user_t));

    if (user == NULL)
        return (NULL);

    unsigned char uuid[16];

    memset(user->uuid, 0, sizeof(user->uuid));
    uuid_generate(uuid);
    uuid_unparse(uuid, user->uuid);
    memset(user->name, 0, sizeof(user->name));
    strncpy(user->name, name, MAX_NAME_LENGTH);
    user->privates = list_create();
    user->use = USE_SERVER;
    user->obj = NULL;
    return (user);
}

bool user_get_id(user_t *user, char *uuid)
{
    return (strcmp(user->uuid, uuid) == 0);
}

void user_delete(user_t *user)
{
    if (user == NULL)
        return;
    list_delete(user->privates, delete_c(private_delete));
    free(user);
}
