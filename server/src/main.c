/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>

#include "server/server.h"

#include "def/code.h"

int main(void)
{
    setbuf(stdout, NULL); // TODO: Debug

    server_t *server = server_create(4242);

    if (server_init(server) == CODE_ERROR) {
        perror("server_init"); // TODO: Debug
        return (CODE_ERROR);
    }
    if (server_run(server) == CODE_ERROR) {
        perror("server_run"); // TODO: Debug
        return (CODE_ERROR);
    }

    server_delete(server);

    return (0);
}
