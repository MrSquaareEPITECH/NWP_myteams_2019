/*
** EPITECH PROJECT, 2020
** server
** File description:
** messages.c
*/

#include "messages.h"

#include <stdlib.h>
#include <string.h>

#include "client/client_util.h"
#include "def/code.h"
#include "def/response.h"
#include "exchange/exchange.h"
#include "message/message.h"
#include "message/message_util.h"
#include "private/private.h"
#include "util/get_or_error.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        error = strfmt(RESPONSE_MESSAGE_LIST_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    if (argc < 2) {
        error = strfmt(RESPONSE_MESSAGE_LIST_KO, "Missing argument");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

static int reply(client_t *client, exchange_t *exchange)
{
    char *response = strfmt(RESPONSE_MESSAGE_LIST_OK, "Success");
    reply_list_t options = {
        response, RESPONSE_MESSAGE_LIST_START, RESPONSE_MESSAGE_LIST_END};

    if (client_reply_list(client, &options, exchange->messages,
            (to_data_t)(message_to_data)) == CODE_ERROR)
        return (CODE_ERROR);
    free(response);
    return (CODE_SUCCESS);
}

int messages_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    user_t *user =
        get_or_error_user_id(client, RESPONSE_MESSAGE_LIST_KO, server, argv[1]);
    private_t *priv = NULL;
    exchange_t *exchange = NULL;

    if (user)
        priv = get_or_error_private(
            client, RESPONSE_MESSAGE_LIST_KO, user, client->user->uuid);
    if (priv)
        exchange = get_or_error_exchange(
            client, RESPONSE_MESSAGE_LIST_KO, server, priv->exchange);
    if (exchange == NULL)
        return (CODE_ERROR);
    if (reply(client, exchange) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
