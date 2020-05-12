/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_list.c
*/

#include "thread_list.h"

#include <stdlib.h>
#include <string.h>

#include "def/code.h"

static thread_t *thread_list_get(thread_list_t *this, const char *uuid)
{
    for (thread_node_t *node = this->begin; node; node = node->next)
        if (strcmp(node->thread->uuid, uuid) == 0)
            return node->thread;

    return (NULL);
}

static int thread_list_push(thread_list_t *this, thread_t *thread)
{
    thread_node_t *node = malloc(sizeof(thread_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->thread = thread;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

thread_list_t *thread_list_create(void)
{
    thread_list_t *this = malloc(sizeof(thread_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->get = thread_list_get;
    this->push = thread_list_push;

    return this;
}

void thread_list_delete(thread_list_t *this)
{
    if (this == NULL)
        return;

    for (thread_node_t *node = this->begin; node;) {
        thread_node_t *current = node;
        node = node->next;
        thread_delete(current->thread);
        free(current);
    }

    free(this);
}
