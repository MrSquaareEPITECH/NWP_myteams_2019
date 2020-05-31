/*
** EPITECH PROJECT, 2020
** cli
** File description:
** use.c
*/

#include <logging_client.h>
#include <stdlib.h>
#include <string.h>

#include "client/client_internal.h"
#include "def/code.h"
#include "subresponse.h"

static int channel_use_subresponse_ko(client_t *client, int argc, char **argv)
{
    (void)(client);
    (void)(argc);

    if (strstr(argv[3], "Team doesn't exist"))
        client_error_unknown_team(argv[4]);
    if (strstr(argv[3], "Channel doesn't exist"))
        client_error_unknown_channel(argv[4]);
    return (CODE_SUCCESS);
}

int channel_use_subresponse(client_t *client, int argc, char **argv)
{
    int rc = 0;

    if (strcmp(argv[2], "KO") == 0)
        rc = channel_use_subresponse_ko(client, argc, argv);
    return (rc);
}
