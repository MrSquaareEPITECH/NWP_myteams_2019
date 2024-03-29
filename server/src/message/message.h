/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_H
#define NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_H

#include <time.h>

#include "def/length.h"

typedef struct message_s message_t;

struct message_s {
    char user[UUID_LENGTH + 1];
    time_t timestamp;
    char body[MAX_BODY_LENGTH + 1];
};

message_t *message_create(const char *user, const char *body);
void message_delete(message_t *message);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_H
