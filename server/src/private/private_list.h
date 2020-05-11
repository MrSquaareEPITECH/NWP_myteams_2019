/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_LIST_H

#include "private.h"

typedef struct private_list_s private_list_t;
typedef struct private_node_s private_node_t;

struct private_node_s {
    private_t *private;
    private_node_t *next;
};

struct private_list_s {
    private_node_t *begin;
    private_node_t *end;

    private_t *(*get)(private_list_t *this, const char *uuid);
    int (*push)(private_list_t *this, private_t *private);
};

private_list_t *private_list_create(void);
void private_list_delete(private_list_t *private_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_LIST_H
