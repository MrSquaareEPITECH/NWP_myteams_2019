/*
** EPITECH PROJECT, 2020
** src
** File description:
** read
*/

#include "my.h"

int get_command(client_t *cli)
{
    write(cli->port, cli->buffer, SIZE_OF_BUFFER);
    return (SUCCESS);
}
