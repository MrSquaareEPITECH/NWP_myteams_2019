/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def/code.h"
#include "server/server.h"
#include "server/server_load.h"
#include "server/server_save.h"

void help(const char *binary)
{
    printf(
        "USAGE: %s port"
        "\n\n",
        binary);
    printf(
        "\t"
        "port"
        "\t"
        "is the port number on which the server socket listens.\n");
}

int main(int argc, char **argv)
{
    if ((argc < 2) || (strcmp(argv[1], "-help") == 0)) {
        help(argv[0]);
        return (CODE_SUCCESS);
    }

    int port = atoi(argv[1]);
    server_t *server = server_create(port);

    server_load(server);
    if (server_init(server) == CODE_ERROR)
        return (CODE_ERROR);
    if (server_run(server) == CODE_ERROR)
        return (CODE_ERROR);
    server_save(server);
    server_delete(server);
    return (0);
}
