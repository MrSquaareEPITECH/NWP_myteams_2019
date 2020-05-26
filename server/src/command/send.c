/*
** EPITECH PROJECT, 2020
** server
** File description:
** send.c
*/

#define _GNU_SOURCE

#include "send.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringext.h>

#include "client/client_util.h"
#include "conversation/conversation.h"
#include "def/code.h"
#include "def/data.h"
#include "def/event.h"
#include "def/response.h"
#include "get_error_util.h"
#include "get_util.h"
#include "message/message.h"
#include "private/private.h"
#include "user/user.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        asprintf(&error, RESPONSE_MESSAGE_SEND_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 3) {
        asprintf(&error, RESPONSE_MESSAGE_SEND_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static conversation_t *retreive_conversation(
    server_t *server, user_t *user1, user_t *user2)
{
    conversation_t *conversation = NULL;
    private_t *priv = get_private(user1, user2->uuid);

    if (priv) {
        conversation = get_conversion(server, priv->uuid);
        return (conversation);
    }

    conversation = conversation_create();

    private_t *priv1 = private_create(conversation->uuid, user2->uuid);
    private_t *priv2 = private_create(conversation->uuid, user1->uuid);

    list_push(user1->privates, priv1);
    list_push(user2->privates, priv2);
    list_push(server->conversations, conversation);
    return (conversation);
}

static message_t *create(char **argv)
{
    char *body = strtrim(argv[2], " \t\"");
    message_t *message = message_create(body);

    free(body);
    return (message);
}

static int reply(client_t *client, message_t *message)
{
    char *response = NULL;
    char *data = NULL;

    asprintf(&response, RESPONSE_MESSAGE_SEND_OK, "Success");
    asprintf(&data, DATA_MESSAGE, message->timestamp, message->body);
    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(client_t *client, message_t *message)
{
    char *data = NULL;
    char *event = strdup(EVENT_MESSAGE_CREATED);

    asprintf(&data, DATA_MESSAGE, message->timestamp, message->body);
    if (client_reply(client, event, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int send_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *receiver_user =
        get_error_user(client, RESPONSE_MESSAGE_SEND_KO, server, argv[1]);

    if (receiver_user == NULL)
        return (CODE_ERROR);

    conversation_t *conversation =
        retreive_conversation(server, client->user, receiver_user);
    message_t *message = create(argv);
    client_t *receiver_client = get_client(server, receiver_user->uuid);

    if (list_push(conversation->messages, message) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, message) == CODE_ERROR)
        return (CODE_ERROR);
    if (receiver_client && (broadcast(receiver_client, message) == CODE_ERROR))
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
