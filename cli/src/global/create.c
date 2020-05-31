/*
** EPITECH PROJECT, 2020
** cli
** File description:
** create.c
*/

#include <logging_client.h>
#include <string.h>

#include "def/code.h"
#include "subresponse.h"

static void global_create_subresponse_ko(
    client_t *client, int argc, char **argv)
{
    (void)(client);
    (void)(argc);

    if (strstr(argv[3], "Not logged"))
        client_error_unauthorized();
}

int global_create_subresponse(client_t *client, int argc, char **argv)
{
    if (strcmp(argv[2], "KO") == 0)
        global_create_subresponse_ko(client, argc, argv);
    return (CODE_SUCCESS);
}
