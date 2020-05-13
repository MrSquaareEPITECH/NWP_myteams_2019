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
#include <stdlib.h>
#include <stdio.h>

#define ERROR_FUNCTION (-1)
#define SUCCESS (0)

typedef struct client_s {
	int fd_client;
	struct sockaddr_in sin;
	socklen_t len;
} client_t;

#endif /* !MY_H_ */
