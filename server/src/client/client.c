/*
** EPITECH PROJECT, 2020
** server
** File description:
** client.c
*/

#include "client.h"

#include <stdlib.h>

client_t *client_create(void)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return (NULL);
    client->sock = socket_create(INADDR_ANY, PF_INET, 0);
    client->queue = list_create();
    client->state = CLIENT_UNKNOWN;
    client->user = NULL;
    return (client);
}

void client_delete(client_t *client)
{
    if (client == NULL)
        return;
    socket_delete(client->sock);
    list_delete(client->queue, free);
    free(client);
}
