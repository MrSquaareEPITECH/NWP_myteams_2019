/*
** EPITECH PROJECT, 2020
** cli
** File description:
** create.c
*/

#include <logging_client.h>
#include <stdlib.h>
#include <string.h>

#include "client/client_internal.h"
#include "def/code.h"
#include "subresponse.h"

int team_create_subresponse_ok(client_t *client, int argc, char **argv)
{
    (void)(argc);
    (void)(argv);

    int argcr = 0;
    char **argvr = 0;

    if (client_receive(client, &argcr, &argvr) == CODE_ERROR)
        return (CODE_ERROR);
    client_print_team_created(argvr[0], argvr[1], argvr[2]);
    return (CODE_SUCCESS);
}

static int team_create_subresponse_ko(client_t *client, int argc, char **argv)
{
    (void)(client);
    (void)(argc);

    if (strstr(argv[3], "Missing argument"))
        client_error_unauthorized();
    if (strstr(argv[3], "Unauthorized"))
        client_error_unauthorized();
    if (strstr(argv[3], "Already exists"))
        client_error_already_exist();
    return (CODE_SUCCESS);
}

int team_create_subresponse(client_t *client, int argc, char **argv)
{
    int rc = 0;

    if (strcmp(argv[2], "OK") == 0)
        rc = team_create_subresponse_ok(client, argc, argv);
    if (strcmp(argv[2], "KO") == 0)
        rc = team_create_subresponse_ko(client, argc, argv);
    return (rc);
}
