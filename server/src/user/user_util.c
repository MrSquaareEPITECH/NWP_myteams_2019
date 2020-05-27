/*
** EPITECH PROJECT, 2020
** server
** File description:
** user_util.c
*/

#include "user_util.h"

#include <stdlib.h>
#include <stringext.h>

#include "def/data.h"
#include "util/string.h"

char *user_to_data(user_t *user)
{
    char *data = strfmt(DATA_USER, user->uuid, user->name, user->status);

    return (data);
}

private_t *user_get_private(user_t *user, const char *uuid)
{
    char *id = strtrim(uuid, "\"");
    private_t *private =
        list_get(user->privates, id, (compare_t)(private_get_id));

    free(id);
    return (private);
}
