/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server.c
*/

#include "server.h"

#include <stdlib.h>

server_t *server_create(void)
{
    server_t *this = malloc(sizeof(server_t));

    if (this == NULL)
        return (NULL);

    this->clients = NULL;
    this->teams = NULL;

    return (this);
}

void server_delete(server_t *this)
{
    if (this == NULL)
        return;

    client_list_delete(this->clients);
    team_list_delete(this->teams);

    free(this);
}
