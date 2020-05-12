/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_list.c
*/

#include "user_list.h"

#include <stdlib.h>
#include <string.h>

#include "def/code.h"

static user_t *user_list_get(user_list_t *this, const char *uuid)
{
    for (user_node_t *node = this->begin; node; node = node->next)
        if (strcmp(node->user->uuid, uuid) == 0)
            return node->user;

    return (NULL);
}

static int user_list_push(user_list_t *this, user_t *user)
{
    user_node_t *node = malloc(sizeof(user_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->user = user;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

user_list_t *user_list_create(void)
{
    user_list_t *this = malloc(sizeof(user_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->get = user_list_get;
    this->push = user_list_push;

    return this;
}

void user_list_delete(user_list_t *this)
{
    if (this == NULL)
        return;

    for (user_node_t *node = this->begin; node;) {
        user_node_t *current = node;
        node = node->next;
        user_delete(current->user);
        free(current);
    }

    free(this);
}
