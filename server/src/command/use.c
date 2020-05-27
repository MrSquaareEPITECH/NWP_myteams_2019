/*
** EPITECH PROJECT, 2020
** server
** File description:
** use.c
*/

#include "use.h"

#include "def/code.h"
#include "def/response.h"
#include "use_internal.h"
#include "util/string.h"

static int validate(server_t *server, client_t *client, int argc, char **argv)
{
    (void)(server);
    (void)(argc);
    (void)(argv);

    char *error = NULL;

    if (client->state != CLIENT_LOGGED) {
        error = strfmt(RESPONSE_GLOBAL_USE_KO, "Not logged");
        list_push(client->queue, error);
        return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

int use_command(server_t *server, client_t *client, int argc, char **argv)
{
    if (validate(server, client, argc, argv) == CODE_ERROR)
        return (CODE_ERROR);

    switch (argc) {
        case 1:
            use_server(server, client, argc, argv);
            break;
        case 2:
            use_team(server, client, argc, argv);
            break;
        case 3:
            use_channel(server, client, argc, argv);
            break;
        default:
            use_thread(server, client, argc, argv);
            break;
    }
    return (CODE_SUCCESS);
}
