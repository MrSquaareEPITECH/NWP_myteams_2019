/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber_list.c
*/

#include "subscriber_list.h"

#include <stdlib.h>

#include "def/code.h"

static int subscriber_list_push(
    subscriber_list_t *this, subscriber_t *subscriber)
{
    subscriber_node_t *node = malloc(sizeof(subscriber_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->subscriber = subscriber;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

subscriber_list_t *subscriber_list_create(void)
{
    subscriber_list_t *this = malloc(sizeof(subscriber_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->push = subscriber_list_push;

    return this;
}

void subscriber_list_delete(subscriber_list_t *this)
{
    if (this == NULL)
        return;

    for (subscriber_node_t *node = this->begin; node;) {
        subscriber_node_t *current = node;
        node = node->next;
        subscriber_delete(current->subscriber);
        free(current);
    }

    free(this);
}
