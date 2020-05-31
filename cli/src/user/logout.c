/*
** EPITECH PROJECT, 2020
** cli
** File description:
** logout.c
*/

#include <logging_client.h>
#include <string.h>

#include "client/client_internal.h"
#include "def/code.h"
#include "subresponse.h"

static int user_logout_subresponse_ko(client_t *client, int argc, char **argv)
{
    (void)(client);
    (void)(argc);

    if (strstr(argv[3], "Not logged"))
        client_error_unauthorized();
    return (CODE_SUCCESS);
}

int user_logout_subresponse(client_t *client, int argc, char **argv)
{
    int rc = 0;

    if (strcmp(argv[2], "KO") == 0)
        rc = user_logout_subresponse_ko(client, argc, argv);
    return (rc);
}
