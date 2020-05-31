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

void list_clear(list_t *list)
{
    if (list == NULL)
        return;
    for (node_t *node = list->begin; node;) {
        node_t *current = node;
        node = node->next;
        free(current);
    }
    free(list);
}
