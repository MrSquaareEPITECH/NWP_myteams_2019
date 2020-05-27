/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_H
#define NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_H

typedef struct thread_s thread_t;

#include <time.h>

#include "def/length.h"

typedef struct comment_s comment_t;

struct comment_s {
    time_t timestamp;
    char body[MAX_BODY_LENGTH + 1];

    thread_t *parent;
};

comment_t *comment_create(thread_t *thread, const char *body);
void comment_delete(comment_t *comment);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_H
