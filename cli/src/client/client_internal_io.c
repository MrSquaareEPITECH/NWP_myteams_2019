/*
** EPITECH PROJECT, 2020
** cli
** File description:
** client_internal_io.c
*/

#include <arrayext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringext.h>

#include "client_internal.h"
#include "def/code.h"

static int has_breakline(int rbytes, const char *buf)
{
    (void)(rbytes);

    if (strchr(buf, '\n'))
        return (1);
    return (0);
}

static int message_to_args(const char *str, int *argc, char ***argv)
{
    char *trim = strtrim(str, " \r\n");

    *argv = strsplitj(trim, " ", "\"");
    if (*argv == NULL)
        return (CODE_ERROR);
    for (size_t i = 0; (*argv)[i]; ++i) {
        char *tmp = (*argv)[i];
        (*argv)[i] = strtrim((*argv)[i], "\"");
        free(tmp);
    }
    *argc = arrlen((const void **)(*argv));
    free(trim);
    return (CODE_SUCCESS);
}

int client_receive(client_t *client, int *argc, char ***argv)
{
    char *message = NULL;

    if (!select_is_set(client->sel, client->sock, SELECT_READ))
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

int client_send(client_t *client, const char *message)
{
    if (!select_is_set(client->sel, client->sock, SELECT_WRITE))
        return (CODE_ERROR);

    int wbytes = socket_send(client->sock, message, strlen(message), 0);

    if (wbytes == 0)
        client->state = CLIENT_DISCONNECTED;
    if (wbytes <= 0)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
