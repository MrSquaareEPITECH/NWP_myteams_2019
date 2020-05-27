/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_comment.c
*/

#include <stdlib.h>

#include "client/client_util.h"
#include "command/list_internal.h"
#include "comment/comment.h"
#include "comment/comment_util.h"
#include "def/code.h"
#include "def/response.h"
#include "thread/thread.h"
#include "util/string.h"

static int reply(client_t *client, thread_t *thread)
{
    char *response = strfmt(RESPONSE_COMMENT_LIST_OK, "Success");
    reply_list_t options = {
        response, RESPONSE_COMMENT_LIST_START, RESPONSE_COMMENT_LIST_END};

    if (client_reply_list(client, &options, thread->comments,
            (to_data_t)(comment_to_data)) == CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int list_comment(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    thread_t *thread = (thread_t *)(client->user->obj);

    if (reply(client, thread) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
