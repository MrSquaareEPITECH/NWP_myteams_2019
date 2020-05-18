/*
** EPITECH PROJECT, 2020
** src
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE_OF_BUFFER (1024)
#define ERROR_FUNCTION (-1)
#define SUCCESS (0)

typedef struct utilities_s {
    struct timeval tv;
    fd_set set_read;
    fd_set a_read;
    fd_set set_write;
    fd_set a_write;
} utilities_t;

typedef struct client_s {
    int port;
	int fd_client;
    char buffer[1024];
	struct sockaddr_in sin;
} client_t;

int get_command(client_t *cli);

#endif /* !MY_H_ */
