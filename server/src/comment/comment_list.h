/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_LIST_H

#include "comment.h"

typedef struct comment_list_s comment_list_t;
typedef struct comment_node_s comment_node_t;

struct comment_node_s {
    comment_t *comment;
    comment_node_t *next;
};

struct comment_list_s {
    comment_node_t *begin;
    comment_node_t *end;

    int (*push)(comment_list_t *this, comment_t *comment);
};

comment_list_t *comment_list_create(void);
void comment_list_delete(comment_list_t *comment_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_LIST_H
