/*
** EPITECH PROJECT, 2020
** src
** File description:
** client
*/

#include "my.h"

int set_client(client_t *cli)
{
    cli->fd_client = socket(AF_INET, SOCK_STREAM, 0);
    if (cli->fd_client < 0) {
        perror("Socket");
        return (ERROR_FUNCTION);
    }
    cli->sin.sin_addr.s_addr = inet_addr("127.0.0.1");
    cli->sin.sin_family = PF_INET;
    cli->sin.sin_port = htons(cli->port);
    if (connect(cli->fd_client, (struct sockaddr *)&cli->sin,
        sizeof(cli->sin)) < 0) {
        perror("Connect");
        return (ERROR_FUNCTION);
    }
    return (SUCCESS);
}

void set_utilities(utilities_t *utils, client_t *client)
{
    FD_ZERO(&utils->a_read);
    FD_ZERO(&utils->a_write);
    FD_SET(client->fd_client, &utils->a_write);
    FD_SET(client->fd_client, &utils->a_read);
}

int main_loop(client_t *cli, utilities_t *utils)
{
    while (1) {
        utils->set_read = utils->a_read;
        utils->set_write = utils->a_write;
        write(0, "> ", 3);
        if (select(FD_SETSIZE, &utils->set_read, &utils->set_write,
            NULL, NULL) < 0) {
            perror("select");
            return (ERROR_FUNCTION);
        }
        cli->buffer = get_command();
        if (cli->buffer == NULL)
            return (ERROR_FUNCTION);
        else
            check_command(cli);
        get_info_server(cli);
    }
    return (SUCCESS);
}

int connect_client(int port)
{
    client_t *cli = malloc(sizeof(client_t));
    utilities_t utils;

    cli->port = port;
    if (set_client(cli) != SUCCESS)
        return (ERROR_FUNCTION);
    set_utilities(&utils, cli);
    if (main_loop(cli, &utils) == ERROR_FUNCTION)
        return (ERROR_FUNCTION);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (ac == 3)
        if (connect_client(atoi(av[2])) != SUCCESS)
            return (ERROR);
    return (0);
}