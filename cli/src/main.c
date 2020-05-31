/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "client/client.h"
#include "def/code.h"

void help(const char *binary)
{
    printf(
        "USAGE: %s ip port"
        "\n",
        binary);
    printf(
        "\t"
        "ip"
        "\t"
        "is the server ip address on which the server socket listens\n");
    printf(
        "\t"
        "port"
        "\t"
        "is the port number on which the server socket listens\n");
}

int main(int argc, char **argv)
{
    if ((argc < 3) || (strcmp(argv[1], "-help") == 0)) {
        help(argv[0]);
        return (CODE_SUCCESS);
    }

    int port = atoi(argv[2]);
    client_t *client = client_create(argv[1], port);

    if (client_init(client) == CODE_ERROR)
        return (CODE_ERROR);
    if (client_run(client) == CODE_ERROR)
        return (CODE_ERROR);
    client_delete(client);
    return (0);
}
