/*
** EPITECH PROJECT, 2020
** src
** File description:
** read
*/

#include "my.h"

int get_command(client_t *cli)
{
    memset(cli->buffer, 0, SIZE_OF_BUFFER);
    recv(cli->fd_client, cli->buffer, SIZE_OF_BUFFER, MSG_DONTWAIT);
    write(cli->fd_client, cli->buffer, SIZE_OF_BUFFER);
    return (SUCCESS);
}
