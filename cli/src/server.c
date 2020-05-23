/*
** EPITECH PROJECT, 2020
** cli
** File description:
** server
*/

#include "my.h"

void get_info_server(client_t *cli)
{
    char *str = NULL;

    recv(cli->port, str, SIZE_OF_BUFFER, MSG_DONTWAIT);
}