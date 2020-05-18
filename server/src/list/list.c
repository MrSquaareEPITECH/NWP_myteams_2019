/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list.c
*/

#include "list.h"

#include <stdlib.h>
#include <string.h>

#include "def/code.h"

list_t *list_create(void)
{
    list_t *this = malloc(sizeof(list_t));

    if (this == NULL)
        return (NULL);
    this->begin = NULL;
    this->end = NULL;
    return this;
}

void *list_get(list_t *this, void *prop, compare_t comp)
{
    for (node_t *node = this->begin; node; node = node->next)
        if (comp(node->obj, prop))
            return node->obj;
    return (NULL);
}

int list_push(list_t *this, void *obj)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return (CODE_ERROR);
    node->obj = obj;
    node->next = NULL;
    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;
    return (CODE_SUCCESS);
}

void list_delete(list_t *this, delete_t del)
{
    if (this == NULL)
        return;

    for (node_t *node = this->begin; node;) {
        node_t *current = node;
        node = node->next;
        del(current->obj);
        free(current);
    }
    free(this);
}
