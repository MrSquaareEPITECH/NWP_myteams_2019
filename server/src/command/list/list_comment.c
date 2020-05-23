/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_comment.c
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "command/list_internal.h"
#include "comment/comment.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "thread/thread.h"

static int reply(client_t *client, thread_t *thread)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_COMMENT_LIST_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_COMMENT_LIST_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = thread->comments->begin; node; node = node->next) {
        char *data = NULL;
        comment_t *comment = (comment_t *)(node->obj);

        asprintf(&data, DATA_COMMENT, comment->timestamp, comment->body);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_COMMENT_LIST_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int list_comment(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    thread_t *thread = (thread_t *)(client->user->obj);

    reply(client, thread);
    return (CODE_SUCCESS);
}
