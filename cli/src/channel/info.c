/*
** EPITECH PROJECT, 2020
** cli
** File description:
** info.c
*/

#include <logging_client.h>
#include <stdlib.h>
#include <string.h>

#include "client/client_internal.h"
#include "def/code.h"
#include "subresponse.h"

static int channel_info_subresponse_ok(client_t *client, int argc, char **argv)
{
    (void)(argc);
    (void)(argv);

    int argcr = 0;
    char **argvr = 0;

    if (client_receive(client, &argcr, &argvr) == CODE_ERROR)
        return (CODE_ERROR);
    client_print_channel(argvr[0], argvr[1], argvr[2]);
    return (CODE_SUCCESS);
}

int channel_info_subresponse(client_t *client, int argc, char **argv)
{
    int rc = 0;

    if (strcmp(argv[2], "OK") == 0)
        rc = channel_info_subresponse_ok(client, argc, argv);
    return (rc);
}
