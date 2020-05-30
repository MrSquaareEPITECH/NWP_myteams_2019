/*
** EPITECH PROJECT, 2020
** server
** File description:
** team_util.h
*/

#ifndef SERVER_SRC_TEAM_TEAM_UTIL_H
#define SERVER_SRC_TEAM_TEAM_UTIL_H

#include "channel/channel.h"
#include "subscriber/subscriber.h"
#include "team.h"

char *team_to_data(team_t *team);
channel_t *team_get_channel(team_t *team, const char *uuid);
subscriber_t *team_get_subscriber(team_t *team, const char *uuid);

#endif // SERVER_SRC_TEAM_TEAM_UTIL_H
