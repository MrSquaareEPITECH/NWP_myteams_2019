/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_list.c
*/

#include "team_list.h"

#include <stdlib.h>
#include <string.h>

#include "def/code.h"

static team_t *team_list_get(team_list_t *this, const char *uuid)
{
    for (team_node_t *node = this->begin; node; node = node->next)
        if (strcmp(node->team->uuid, uuid) == 0)
            return node->team;

    return (NULL);
}

static int team_list_push(team_list_t *this, team_t *team)
{
    team_node_t *node = malloc(sizeof(team_node_t));

    if (node == NULL)
        return (CODE_ERROR);

    node->team = team;
    node->next = NULL;

    if (this->begin == NULL)
        this->begin = node;
    else
        this->end->next = node;
    this->end = node;

    return (CODE_SUCCESS);
}

team_list_t *team_list_create(void)
{
    team_list_t *this = malloc(sizeof(team_list_t));

    if (this == NULL)
        return (NULL);

    this->begin = NULL;
    this->end = NULL;

    this->get = team_list_get;
    this->push = team_list_push;

    return this;
}

void team_list_delete(team_list_t *this)
{
    if (this == NULL)
        return;

    for (team_node_t *node = this->begin; node;) {
        team_node_t* current = node;
        node = node->next;
        team_delete(current->team);
        free(current);
    }

    free(this);
}
