/*
** EPITECH PROJECT, 2020
** cli
** File description:
** subresponse.c
*/

#include "subresponse.h"

#include <string.h>

#include "def/code.h"

static const response_t *team_subresponse_get(const char *name)
{
    for (size_t i = 0; TEAM_SUBRESPONSES[i].name; ++i)
        if (strcmp(TEAM_SUBRESPONSES[i].name, name) == 0)
            return (&TEAM_SUBRESPONSES[i]);
    return (NULL);
}

int team_response(client_t *client, int argc, char **argv)
{
    const response_t *response = team_subresponse_get(argv[1]);

    if (response == NULL)
        return (CODE_ERROR);
    if (response->func(client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
