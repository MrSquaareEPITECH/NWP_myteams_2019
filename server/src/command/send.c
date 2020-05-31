/*
** EPITECH PROJECT, 2020
** server
** File description:
** send.c
*/

#include "send.h"

#include <logging_server.h>
#include <string.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/event.h"
#include "def/response.h"
#include "exchange/exchange.h"
#include "message/message.h"
#include "message/message_util.h"
#include "send_internal.h"
#include "server/server_util.h"
#include "user/user.h"
#include "util/get_or_error.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        error = strfmt(RESPONSE_MESSAGE_SEND_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 3) {
        error = strfmt(RESPONSE_MESSAGE_SEND_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static exchange_t *get_or_create_exchange(
    server_t *server, user_t *user1, user_t *user2)
{
    exchange_t *exchange = get_exchange(server, user1, user2);

    if (exchange == NULL)
        exchange = create_exchange(server, user1, user2);
    return (exchange);
}

static int reply(client_t *client, message_t *message)
{
    char *response = strfmt(RESPONSE_MESSAGE_SEND_OK, "Success");
    char *data = message_to_data(message);

    if (client_reply(client, response, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

static int broadcast(client_t *client, message_t *message)
{
    char *data = message_to_data(message);
    char *event = strdup(EVENT_MESSAGE_CREATED);

    if (client_reply(client, event, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int send_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *ruser = get_or_error_user_id(
        client, RESPONSE_MESSAGE_SEND_KOID, server, argv[1]);

    if (ruser == NULL) return (CODE_ERROR);

    exchange_t *exchange = get_or_create_exchange(server, client->user, ruser);
    message_t *message = create_message(client->user->uuid, argv);
    client_t *rclient = server_get_client(server, ruser->uuid);

    if (list_push(exchange->messages, message) == CODE_ERROR)
        return (CODE_ERROR);
    if (reply(client, message) == CODE_ERROR) return (CODE_ERROR);
    if (rclient && (broadcast(rclient, message) == CODE_ERROR))
        return (CODE_ERROR);
    server_event_private_message_sended(
        client->user->uuid, ruser->uuid, message->body);
    return (CODE_SUCCESS);
}
