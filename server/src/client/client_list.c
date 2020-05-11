/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** client_list.c
*/

#include "client_list.h"

#include <stdlib.h>

#include "def/code.h"

static int client_list_push(client_list_t *this, client_t *client)
{
    client_node_t *node = malloc(sizeof(client_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->client = client;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

client_list_t *client_list_create(void)
{
    client_list_t *this = malloc(sizeof(client_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->push = client_list_push;

    return this;
}

void client_list_delete(client_list_t *this)
{
    if (this == NULL)
        return;

    for (client_node_t *node = this->begin; node;) {
        client_node_t* current = node;
        node = node->next;
        client_delete(current->client);
        free(current);
    }

    free(this);
}
