/*
** EPITECH PROJECT, 2020
** cli
** File description:
** client.c
*/

#include "client.h"

#include <arpa/inet.h>
#include <socket.h>
#include <stdlib.h>

#include "client_internal.h"
#include "client_signal.h"
#include "def/code.h"

client_t *client_create(const char *ip, uint16_t port)
{
    client_t *client = malloc(sizeof(client_t));
    timeval_t *timeval = client_signal_timeval(1, 0);
    uint32_t addr = inet_addr(ip);

    if (client == NULL)
        return (NULL);
    client->input.fd = 0;
    client->sel = select_create(timeval);
    client->sock = socket_create(addr, PF_INET, port);
    client->queue = list_create();
    client->state = CLIENT_UNKNOWN;
    return (client);
}

int client_init(client_t *client)
{
    if (socket_connect(client->sock, SOCK_STREAM) == CODE_INVALID)
        return (CODE_ERROR);
    client->state = CLIENT_CONNECTED;
    return (CODE_SUCCESS);
}

int client_run(client_t *client)
{
    if (client_signal_init() == CODE_ERROR)
        return (CODE_ERROR);
    select_set(client->sel, &client->input, SELECT_READ);
    select_set(client->sel, client->sock, SELECT_READ | SELECT_WRITE);

    while (true) {
        if (select_monitor(client->sel) == CODE_ERROR)
            return (CODE_ERROR);
        if (client_signal_get(-1))
            return (CODE_SUCCESS);
        if (client->state == CLIENT_DISCONNECTED)
            return (CODE_SUCCESS);
        client_input(client);
        client_notify(client);
        client_execute(client);
    }
}

void client_delete(client_t *client)
{
    if (client == NULL)
        return;
    select_delete(client->sel);
    socket_delete(client->sock);
}
