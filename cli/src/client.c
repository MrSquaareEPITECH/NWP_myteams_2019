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
        perror("Socket: ");
        return (ERROR_FUNCTION);
    }
    cli->sin.sin_addr.s_addr = htonl(INADDR_ANY);
	cli->sin.sin_port = htons(cli->port);
    if (inet_pton(AF_INET, "127.0.0.1" , &cli->sin.sin_addr.s_addr) < 0) {
        perror("Inet: ");
        return (ERROR_FUNCTION);
    }
    if (connect(cli->fd_client, (struct sockaddr*)&cli->sin, sizeof(cli->sin)) < 0) {
        perror("Connect: ");
        return (ERROR_FUNCTION);
    }
    return (SUCCESS);
}

int main_loop(client_t *cli)
{
    int ret = 0;

    memset(cli->buffer, 0, SIZE_OF_BUFFER);
    int flags = fcntl(cli->fd_client, F_GETFL, 0);
    if (fcntl(cli->fd_client, F_SETFL, O_NONBLOCK) < 0) {
        perror("fcntl : ");
        return (ERROR_FUNCTION);
    }
    while (1) {
        ret = read(cli->fd_client, cli->buffer, SIZE_OF_BUFFER);
        if (ret > 0) {
            write(cli->fd_client, cli->buffer, SIZE_OF_BUFFER);
            memset(cli->buffer, 0, SIZE_OF_BUFFER);
            ret = 0;
            break;
        }
    }
    return (SUCCESS);
}

int connect_client(int port)
{
    client_t *cli = malloc(sizeof(client_t));

    cli->port = port;
    if (set_client(cli) != SUCCESS)
        return (ERROR_FUNCTION);
    main_loop(cli);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (ac == 3)
        if (connect_client(atoi(av[2])) != SUCCESS)
            return (ERROR);
    return (0);
}