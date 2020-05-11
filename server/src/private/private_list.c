/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_list.c
*/

#include "private_list.h"

#include <stdlib.h>
#include <string.h>

#include "def/code.h"

static private_t *private_list_get(private_list_t *this, const char *uuid)
{
    for (private_node_t *node = this->begin; node; node = node->next)
        if (strcmp(node->private->uuid, uuid) == 0)
            return node->private;

    return (NULL);
}

static int private_list_push(private_list_t *this, private_t *private)
{
    private_node_t *node = malloc(sizeof(private_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->private = private;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

private_list_t *private_list_create(void)
{
    private_list_t *this = malloc(sizeof(private_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->get = private_list_get;
    this->push = private_list_push;

    return this;
}

void private_list_delete(private_list_t *this)
{
    if (this == NULL)
        return;

    for (private_node_t *node = this->begin; node;) {
        private_node_t* current = node;
        node = node->next;
        private_delete(current->private);
        free(current);
    }

    free(this);
}
