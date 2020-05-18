/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_H
#define NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_H

#include <time.h>

#include "def/length.h"
#include "list/list.h"

typedef struct thread_s thread_t;

struct thread_s {
    char uuid[UUID_LENGTH + 1];
    time_t timestamp;
    char name[MAX_NAME_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];

    list_t *comments;
};

thread_t *thread_create(const char *name, const char *description);
void thread_delete(thread_t *this);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_H
