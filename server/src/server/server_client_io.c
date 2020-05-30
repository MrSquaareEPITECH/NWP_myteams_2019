/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_client_io.c
*/

#include <arrayext.h>
#include <stdlib.h>
#include <string.h>
#include <stringext.h>

#include "client/client.h"
#include "def/code.h"
#include "server.h"
#include "server_client.h"

static int has_breakline(int rbytes, const char *buf)
{
    if (memchr(buf, '\n', rbytes))
        return (1);
    return (0);
}

static int message_to_args(const char *str, int *argc, char ***argv)
{
    char *trim = strtrim(str, " \r\n");

    *argv = strsplitj(trim, " ", "\"");
    if (*argv == NULL)
        return (CODE_ERROR);
    *argc = arrlen((const void **)(*argv));
    free(trim);
    return (CODE_SUCCESS);
}

int server_client_receive(
    server_t *server, client_t *client, int *argc, char ***argv)
{
    char *message = NULL;

    if (!select_is_set(server->sel, client->sock, SELECT_READ))
        return (CODE_ERROR);

    int rbytes = socket_receivew(client->sock, &message, has_breakline, 0);

    if (rbytes == 0)
        client->state = CLIENT_DISCONNECTED;
    if (rbytes <= 0)
        return (CODE_ERROR);
    if (message_to_args(message, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);
    free(message);
    return (CODE_SUCCESS);
}

int server_client_send(server_t *server, client_t *client, const char *message)
{
    if (!select_is_set(server->sel, client->sock, SELECT_WRITE))
        return (CODE_ERROR);

    int wbytes = socket_send(client->sock, message, strlen(message), 0);

    if (wbytes == 0)
        client->state = CLIENT_DISCONNECTED;
    if (wbytes <= 0)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
