/*
** EPITECH PROJECT, 2020
** server
** File description:
** thread_util.c
*/

#include "thread_util.h"

#include "def/data.h"
#include "util/string.h"

char *thread_to_data(thread_t *thread)
{
    char *data = strfmt(DATA_THREAD, thread->uuid, thread->user,
        thread->timestamp, thread->name, thread->body);

    return (data);
}
