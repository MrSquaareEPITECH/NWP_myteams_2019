/*
** EPITECH PROJECT, 2020
** server
** File description:
** server.c
*/

#include "server.h"

#include <memory.h>
#include <signal.h>
#include <stdlib.h>

#include "client/client.h"
#include "def/code.h"
#include "exchange/exchange.h"
#include "server_internal.h"
#include "server_signal.h"
#include "team/team.h"
#include "user/user.h"

server_t *server_create(uint16_t port)
{
    server_t *server = malloc(sizeof(server_t));
    timeval_t *timeval = server_signal_timeval(1, 0);

    if (server == NULL)
        return (NULL);
    server->sel = select_create(timeval);
    server->sock = socket_create(INADDR_ANY, PF_INET, port);
    server->clients = list_create();
    server->teams = NULL;
    server->exchanges = NULL;
    server->users = NULL;
    return (server);
}

int server_init(server_t *server)
{
    if (socket_bind(server->sock, SOCK_STREAM) == CODE_INVALID)
        return (CODE_ERROR);
    if (socket_listen(server->sock, 1) == CODE_INVALID)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}

int server_run(server_t *server)
{
    if (server_signal_init() == CODE_ERROR)
        return (CODE_ERROR);
    select_set(server->sel, server->sock, SELECT_READ | SELECT_WRITE);
    while (true) {
        if (select_monitor(server->sel) == CODE_ERROR)
            return (CODE_ERROR);
        if (server_signal_get(-1))
            return (CODE_SUCCESS);
        if (server_accept(server) == CODE_ERROR)
            return (CODE_ERROR);
        if (server_clear(server) == CODE_ERROR)
            return (CODE_ERROR);
        if (server_execute(server) == CODE_ERROR)
            return (CODE_ERROR);
    }
    return (CODE_SUCCESS);
}

void server_delete(server_t *server)
{
    if (server == NULL)
        return;
    select_delete(server->sel);
    socket_delete(server->sock);
    list_delete(server->clients, delete_c(client_delete));
    list_delete(server->teams, delete_c(team_delete));
    list_delete(server->exchanges, delete_c(exchange_delete));
    list_delete(server->users, delete_c(user_delete));
    free(server);
}
