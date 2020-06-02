/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_node.c
*/

#include <stdlib.h>

#include "def/code.h"
#include "list.h"

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

void *list_pop(list_t *list)
{
    if (list->begin == NULL)
        return (NULL);

    node_t *node = list->begin;

    if (node == list->end)
        list->end = NULL;
    list->begin = node->next;
    return (node->obj);
}

int list_remove(list_t *list, void *obj)
{
    if (list->begin == NULL)
        return (CODE_ERROR);
    if (list->begin->obj == obj) {
        list_pop(list);
        return (CODE_SUCCESS);
    }

    node_t *prev = list->begin;
    node_t *node = prev->next;

    for (; node && (node->obj != obj); prev = prev->next, node = prev->next) ;
    if (node == NULL)
        return (CODE_ERROR);
    if (list->end->obj == obj)
        list->end = prev;
    prev->next = node->next;
    return (CODE_SUCCESS);
}
