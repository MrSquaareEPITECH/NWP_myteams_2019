/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_LIST_H

#include "thread.h"

typedef struct thread_list_s thread_list_t;
typedef struct thread_node_s thread_node_t;

struct thread_node_s {
    thread_t *thread;
    thread_node_t *next;
};

struct thread_list_s {
    thread_node_t *begin;
    thread_node_t *end;

    thread_t *(*get)(thread_list_t *this, const char *uuid);
    int (*push)(thread_list_t *this, thread_t *thread);
};

thread_list_t *thread_list_create(void);
void thread_list_delete(thread_list_t *thread_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_LIST_H
