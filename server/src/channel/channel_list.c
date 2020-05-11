/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_list.c
*/

#include "channel_list.h"

#include <stdlib.h>
#include <string.h>

#include "def/code.h"

static channel_t *channel_list_get(channel_list_t *this, const char *uuid)
{
    for (channel_node_t *node = this->begin; node; node = node->next)
        if (strcmp(node->channel->uuid, uuid) == 0)
            return node->channel;

    return (NULL);
}

static int channel_list_push(channel_list_t *this, channel_t *channel)
{
    channel_node_t *node = malloc(sizeof(channel_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->channel = channel;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

channel_list_t *channel_list_create(void)
{
    channel_list_t *this = malloc(sizeof(channel_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->get = channel_list_get;
    this->push = channel_list_push;

    return this;
}

void channel_list_delete(channel_list_t *this)
{
    if (this == NULL)
        return;

    for (channel_node_t *node = this->begin; node;) {
        channel_node_t* current = node;
        node = node->next;
        channel_delete(current->channel);
        free(current);
    }

    free(this);
}
