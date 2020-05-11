/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client.c
*/

#include "client.h"

#include <stdlib.h>

client_t *client_create(void)
{
    client_t *this = malloc(sizeof(client_t));

    if (this == NULL)
        return (NULL);

    this->user = NULL;

    return (this);
}

void client_delete(client_t *this)
{
    if (this == NULL)
        return;

    user_delete(this->user);

    free(this);
}
