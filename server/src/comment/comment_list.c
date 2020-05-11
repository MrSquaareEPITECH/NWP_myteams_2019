/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment_list.c
*/

#include "comment_list.h"

#include <stdlib.h>

#include "def/code.h"

static int comment_list_push(comment_list_t *this, comment_t *comment)
{
    comment_node_t *node = malloc(sizeof(comment_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->comment = comment;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

comment_list_t *comment_list_create(void)
{
    comment_list_t *this = malloc(sizeof(comment_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->push = comment_list_push;

    return this;
}

void comment_list_delete(comment_list_t *this)
{
    if (this == NULL)
        return;

    for (comment_node_t *node = this->begin; node;) {
        comment_node_t* current = node;
        node = node->next;
        comment_delete(current->comment);
        free(current);
    }

    free(this);
}
