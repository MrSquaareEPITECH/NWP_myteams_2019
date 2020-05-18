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
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL)
        return (NULL);
    list->begin = NULL;
    list->end = NULL;
    return list;
}

void *list_get(list_t *list, void *prop, compare_t comp)
{
    for (node_t *node = list->begin; node; node = node->next)
        if (comp(node->obj, prop))
            return node->obj;
    return (NULL);
}

int list_push(list_t *list, void *obj)
{
    node_t *node = malloc(sizeof(node_t));

    if (node == NULL)
        return (CODE_ERROR);
    node->obj = obj;
    node->next = NULL;
    if (list->begin == NULL)
        list->begin = node;
    else
        list->end->next = node;
    list->end = node;
    return (CODE_SUCCESS);
}

void list_delete(list_t *list, delete_t del)
{
    if (list == NULL)
        return;

    for (node_t *node = list->begin; node;) {
        node_t *current = node;
        node = node->next;
        del(current->obj);
        free(current);
    }
    free(list);
}
