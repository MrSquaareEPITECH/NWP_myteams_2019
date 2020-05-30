/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>

#include "def/code.h"
#include "server/server.h"
#include "server/server_load.h"
#include "server/server_save.h"

int main(void)
{
    setbuf(stdout, NULL); // TODO: Debug

    server_t *server = server_create(4242);

    server_load(server);
    if (server_init(server) == CODE_ERROR) {
        perror("server_init"); // TODO: Debug
        return (CODE_ERROR);
    }
    if (server_run(server) == CODE_ERROR) {
        perror("server_run"); // TODO: Debug
        return (CODE_ERROR);
    }
    server_save(server);
    server_delete(server);
    return (0);
}
