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

static int message_list_subresponse_ok(client_t *client, int argc, char **argv)
{
    (void)(argc);
    (void)(argv);

    int argcr = 0;
    char **argvr = NULL;

    client_receive(client, &argcr, &argvr);
    arrfree((void **)(argvr), free);
    client_receive(client, &argcr, &argvr);
    while ((argcr >= 3) && ((strcmp(argvr[2], "END") != 0))) {
        client_private_message_print_messages(
            argvr[0], strtol(argvr[1], NULL, 10), argvr[2]);
        arrfree((void **)(argvr), free);
        client_receive(client, &argcr, &argvr);
    }
    arrfree((void **)(argvr), free);
    return (CODE_SUCCESS);
}

static int message_list_subresponse_ko(client_t *client, int argc, char **argv)
{
    (void)(client);
    (void)(argc);

    if (strstr(argv[3], "Not logged"))
        client_error_unauthorized();
    if (strstr(argv[3], "Missing argument"))
        client_error_unauthorized();
    if (strstr(argv[3], "User doesn't exist"))
        client_error_unknown_user(argv[4]);
    return (CODE_SUCCESS);
}

int message_list_subresponse(client_t *client, int argc, char **argv)
{
    int rc = 0;

    if (strcmp(argv[2], "OK") == 0)
        rc = message_list_subresponse_ok(client, argc, argv);
    if (strcmp(argv[2], "KO") == 0)
        rc = message_list_subresponse_ko(client, argc, argv);
    return (rc);
}
