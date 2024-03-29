/*
** EPITECH PROJECT, 2020
** server
** File description:
** channel_util.h
*/

#ifndef SERVER_SRC_CHANNEL_CHANNEL_UTIL_H
#define SERVER_SRC_CHANNEL_CHANNEL_UTIL_H

#include "channel.h"
#include "thread/thread.h"

char *channel_to_data(channel_t *channel);
thread_t *channel_get_thread_id(channel_t *channel, const char *uuid);
thread_t *channel_get_thread_name(channel_t *channel, const char *name);

#endif // SERVER_SRC_CHANNEL_CHANNEL_UTIL_H
