/*
** EPITECH PROJECT, 2020
** src
** File description:
** client
*/

#include "my.h"

void set_utilities(client_t *client, utilities_t *utils)
{
    utils->tv.tv_usec = 10000;
    FD_ZERO(&utils->a_read);
    FD_ZERO(&utils->a_write);
    FD_SET(client->fd_client, &utils->a_write);
    FD_SET(client->fd_client, &utils->a_read);
}

int set_client(client_t *cli)
{
	cli->fd_client = socket(AF_INET, SOCK_STREAM, 0);
    if (cli->fd_client < 0) {
        perror("Socket: ");
        return (ERROR_FUNCTION);
    }
	cli->sin.sin_port = htons(cli->port);
	cli->sin.sin_family = AF_INET;
    if (inet_pton(AF_INET, "127.0.0.1" , &cli->sin.sin_addr.s_addr) < 0) {
        perror("Connect: ");
        return (ERROR_FUNCTION);
    }
    if (connect(cli->fd_client, (struct sockaddr*)&cli->sin, sizeof(cli->sin)) < 0) {
        perror("Connect: ");
        return (ERROR_FUNCTION);
    }
    return (SUCCESS);
}

int main_loop(client_t *cli, utilities_t *utils)
{
    int loop = 0;

    while (loop) {
        utils->set_read = utils->a_read;
        utils->set_write = utils->a_write;
        if (select(FD_SETSIZE, &utils->set_read, NULL, NULL, &utils->tv) < 0) {
            perror("select : ");
            return (ERROR_FUNCTION);
        }
        if (FD_ISSET(cli->fd_client, &utils->set_read))
            get_command(cli);
    }
    return (SUCCESS);
}

void connect_client(int port)
{
    client_t *cli = malloc(sizeof(client_t));
    utilities_t utils;

    cli->port = port;
    set_client(cli);
    set_utilities(cli, &utils);
    main_loop(cli, &utils);
}

int main(int ac, char **av)
{
    if (ac == 3)
        connect_client(atoi(av[2]));
    return (0);
}