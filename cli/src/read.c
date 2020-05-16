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
    read(cli->port, cli->buffer, SIZE_OF_BUFFER);
    write(cli->port, cli->buffer, SIZE_OF_BUFFER);
    return (SUCCESS);
}
