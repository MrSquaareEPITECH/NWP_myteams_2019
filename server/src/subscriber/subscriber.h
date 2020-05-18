/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_H
#define NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_H

#include "def/length.h"

typedef struct subscriber_s subscriber_t;

struct subscriber_s {
    char uuid[UUID_LENGTH];
};

subscriber_t *subscriber_create(const char *uuid);
void subscriber_delete(subscriber_t *subscriber);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_H
