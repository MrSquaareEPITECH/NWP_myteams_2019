/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_H
#define NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_H

#include "def/length.h"
#include "list/list.h"

typedef struct channel_s channel_t;

struct channel_s {
    char uuid[UUID_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
    char description[MAX_DESCRIPTION_LENGTH + 1];

    list_t *threads;
};

channel_t *channel_create(const char *name, const char *description);
void channel_delete(channel_t *channel);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_H
