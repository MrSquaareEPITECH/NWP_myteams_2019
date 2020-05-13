/*
** EPITECH PROJECT, 2020
** src
** File description:
** client
*/

#include "my.h"

// int get_command(client_t *cli)
// {
//     memset(cli->buffer, 0, SIZE_OF_BUFFER);
//     read(cli->port, cli->buffer, SIZE_OF_BUFFER);
//     if (my_strcmp(buffer, "Hello world\n") == 0) {
//         fprintf(fd_serve, "close\n");
//         close(fd_client);
//         return (0);
//     }
// }

void main_loop(client_t *cli)
{
    while (loop) {
//        get_command();
    }
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
    if (connect(cli->fd_client, (struct sockaddr*)&cli->sin, cli->len) < 0) {
        perror("Connect: ");
        return (ERROR_FUNCTION);
    }
    return (SUCCESS);
}

void connect_client(int port)
{
    client_t *cli = malloc(sizeof(client_t));

    cli->port = port;
    set_client(cli);
    main_loop(cli);
}

int main(int ac, char **av)
{
    if (ac == 3)
        connect_client(atoi(av[2]));
    return (0);
}