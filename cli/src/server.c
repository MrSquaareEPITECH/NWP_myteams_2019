/*
** EPITECH PROJECT, 2020
** cli
** File description:
** server
*/

#include "my.h"

int get_info_server(client_t *cli)
{
    char *str = NULL;
    int ret = 0;

    str = malloc(sizeof(char) * (SIZE_OF_BUFFER + 1));
    if (str == NULL)
        return (ERROR_FUNCTION);
    ret = recv(cli->port, str, SIZE_OF_BUFFER, MSG_DONTWAIT);
    if (ret == EAGAIN || ret == EWOULDBLOCK)
        parse_msg(cli, str);
    return (SUCCESS);
}
//check retour receive pour fin de lecture serveur
