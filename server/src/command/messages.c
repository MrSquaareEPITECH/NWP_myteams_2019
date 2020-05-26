/*
** EPITECH PROJECT, 2020
** server
** File description:
** messages.c
*/

#define _GNU_SOURCE

#include "messages.h"

#include <stdio.h>
#include <string.h>

#include "conversation/conversation.h"
#include "def/code.h"
#include "def/data.h"
#include "def/response.h"
#include "get_error_util.h"
#include "message/message.h"
#include "private/private.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_MESSAGE_LIST_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        asprintf(&error, RESPONSE_MESSAGE_LIST_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, conversation_t *conversation)
{
    char *response = NULL;

    asprintf(&response, RESPONSE_MESSAGE_LIST_OK, "Success");
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, strdup(RESPONSE_MESSAGE_LIST_START)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    for (node_t *node = conversation->messages->begin; node;
         node = node->next) {
        char *data = NULL;
        message_t *message = (message_t *)(node->obj);

        asprintf(&data, DATA_MESSAGE, message->timestamp, message->body);
        if (list_push(client->queue, data) == CODE_ERROR)
            return (CODE_ERROR);
    }
    if (list_push(client->queue, strdup(RESPONSE_MESSAGE_LIST_END)) ==
        CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_ERROR);
}

int messages_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    private_t *priv = get_error_private(
        client, RESPONSE_MESSAGE_SEND_KO, client->user, argv[1]);

    if (priv == NULL)
        return (CODE_ERROR);

    conversation_t *conversation = get_error_conversation(
        client, RESPONSE_MESSAGE_SEND_KO, server, priv->uuid);

    if (conversation == NULL)
        return (CODE_ERROR);
    if (reply(client, conversation) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
