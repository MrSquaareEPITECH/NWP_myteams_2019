/*
** EPITECH PROJECT, 2020
** server
** File description:
** create_comment.c
*/

#include <stdlib.h>
#include <stringext.h>

#include "channel/channel.h"
#include "client/client_util.h"
#include "command/create_internal.h"
#include "comment/comment.h"
#include "comment/comment_util.h"
#include "def/code.h"
#include "def/event.h"
#include "def/response.h"
#include "server/server_util.h"
#include "thread/thread.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (argc < 2) {
        error = strfmt(RESPONSE_COMMENT_CREATE_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static comment_t *create(thread_t *thread, const char *user, char **argv)
{
    char *body = strtrim(argv[1], "\"");
    comment_t *comment = comment_create(thread, user, body);

    free(body);
    return (comment);
}

static int reply(client_t *client, comment_t *comment)
{
    char *response = strfmt(RESPONSE_COMMENT_CREATE_OK, "Success");
    char *data = comment_to_data(comment);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(server_t *server, comment_t *comment)
{
    list_t *clients =
        server_get_team_clients(server, comment->parent->parent->parent);
    char *data = comment_to_data(comment);

    if (server_broadcast(clients, EVENT_COMMENT_CREATED, data) == CODE_ERROR)
        return (CODE_ERROR);
    list_clear(clients);
    free(data);
    return (CODE_SUCCESS);
}

int create_comment(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    thread_t *thread = (thread_t *)(client->user->obj);
    comment_t *comment = create(thread, client->user->uuid, argv);

    if (comment == NULL)
        return (CODE_ERROR);
    if (list_push(thread->comments, comment) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, comment) == CODE_ERROR)
        return (CODE_ERROR);
    if (broadcast(server, comment) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
