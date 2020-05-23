/*
** EPITECH PROJECT, 2020
** src
** File description:
** handle_command
*/

#include "my.h"

void handle_create(client_t *cli)
{
    int args = count_args(cli->buffer);

    if (args == 1 || args == 2)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    else
        write(cli->fd_client, "/create error\n", 15);
}

void handle_send(client_t *cli)
{
    int args = count_args(cli->buffer);

    if (args == 2)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    else
        write(cli->fd_client, "/send error\n", 13);
}

void handle_subscribe(client_t *cli, bool i)
{
    int args = count_args(cli->buffer);

    if (i == 0) {
        if (args == 1)
            send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
        else
            write(cli->fd_client, "/unsuscribe error\n", 18);
    } else {
        if (args == 1)
            send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
        else
            write(cli->fd_client, "/suscribe error\n", 16);
    }
}

void handle_login(client_t *cli)
{
    int args = count_args(cli->buffer);

    if (args == 1)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    else
        write(cli->fd_client, "/login error\n", 14);
}

void handle_user(client_t *cli)
{
    int args = count_args(cli->buffer);

    if (args == 1)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    else
        write(cli->fd_client, "/user error\n", 13);
}