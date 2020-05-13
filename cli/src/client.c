/*
** EPITECH PROJECT, 2020
** src
** File description:
** client
*/

#include "my.h"

// int client_loop(int fd_serve, int fd_client)
// {
//     char buffer[1024] = {0};

//     read(fd_serve, buffer, 1024);
//     if (my_strcmp(buffer, "Hello world\n") == 0) {
//         write(fd_serve, "close\n", 6);
//         close(fd_client);
//         return (0);
//     }
// }

int set_client(client_t *cli, int port)
{
	cli->fd_client = socket(AF_INET, SOCK_STREAM, 0);
    if (cli->fd_client < 0) {
        perror("Socket: ");
        return (ERROR_FUNCTION);
    }
	cli->sin.sin_port = htons(port);
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

    set_client(cli, port);
//    write(port, "close\n", 6);
//    client_loop(port, fd_client);
}

int main(int ac, char **av)
{
    if (ac == 3)
        connect_client(atoi(av[2]));
    return (0);
}