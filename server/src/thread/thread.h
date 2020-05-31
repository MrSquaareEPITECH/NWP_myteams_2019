/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_H
#define NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_H

typedef struct channel_s channel_t;

#include <time.h>

#include "def/length.h"
#include "list/list.h"

typedef struct thread_s thread_t;

struct thread_s {
    char uuid[UUID_LENGTH + 1];
    char user[UUID_LENGTH + 1];
    time_t timestamp;
    char name[MAX_NAME_LENGTH + 1];
    char body[MAX_BODY_LENGTH + 1];

    channel_t *parent;
    list_t *comments;
};

thread_t *thread_create(
    channel_t *parent, const char *user, const char *name, const char *body);
bool thread_get_id(thread_t *thread, char *uuid);
bool thread_get_name(thread_t *thread, char *name);
void thread_delete(thread_t *thread);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_H
