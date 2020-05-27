/*
** EPITECH PROJECT, 2020
** server
** File description:
** info_thread.c
*/

#include "client/client_util.h"
#include "command/info_internal.h"
#include "def/code.h"
#include "def/response.h"
#include "thread/thread.h"
#include "thread/thread_util.h"
#include "util/string.h"

static int reply(client_t *client, thread_t *thread)
{
    char *response = strfmt(RESPONSE_THREAD_INFO_OK, "Success");
    char *data = thread_to_data(thread);

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
