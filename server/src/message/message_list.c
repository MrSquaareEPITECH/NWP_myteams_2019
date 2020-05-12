/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_list.c
*/

#include "message_list.h"

#include <stdlib.h>

#include "def/code.h"

static int message_list_push(message_list_t *this, message_t *message)
{
    message_node_t *node = malloc(sizeof(message_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->message = message;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

message_list_t *message_list_create(void)
{
    message_list_t *this = malloc(sizeof(message_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->push = message_list_push;

    return this;
}

void message_list_delete(message_list_t *this)
{
    if (this == NULL)
        return;

    for (message_node_t *node = this->begin; node;) {
        message_node_t *current = node;
        node = node->next;
        message_delete(current->message);
        free(current);
    }

    free(this);
}
