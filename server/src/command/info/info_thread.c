/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_thread.c
*/

#define _GNU_SOURCE

#include <stdio.h>

#include "client/client_util.h"
#include "command/info_internal.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "thread/thread.h"

static int reply(client_t *client, thread_t *thread)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_THREAD_INFO_OK, "Success");
    asprintf(&data, DATA_THREAD, thread->uuid, thread->timestamp, thread->name,
        thread->body);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int info_thread(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    thread_t *thread = (thread_t *)(client->user->obj);

    if (reply(client, thread) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
