/*
** EPITECH PROJECT, 2020
** cli
** File description:
** list.c
*/

#include <arrayext.h>
#include <logging_client.h>
#include <stdlib.h>
#include <string.h>

#include "client/client_internal.h"
#include "def/code.h"
#include "subresponse.h"

static int thread_list_subresponse_ok(client_t *client, int argc, char **argv)
{
    (void)(argc);
    (void)(argv);

    int argcr = 0;
    char **argvr = NULL;

    client_receive(client, &argcr, &argvr);
    arrfree((void **)(argvr), free);
    client_receive(client, &argcr, &argvr);
    while ((argcr >= 3) && ((strcmp(argvr[2], "END") != 0))) {
        client_channel_print_threads(
            argvr[0], argvr[1], strtol(argvr[2], NULL, 10), argvr[3], argvr[4]);
        arrfree((void **)(argvr), free);
        client_receive(client, &argcr, &argvr);
    }
    arrfree((void **)(argvr), free);
    return (CODE_SUCCESS);
}

int thread_list_subresponse(client_t *client, int argc, char **argv)
{
    int rc = 0;

    if (strcmp(argv[2], "OK") == 0)
        rc = thread_list_subresponse_ok(client, argc, argv);
    return (rc);
}
