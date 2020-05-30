/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_signal.h
*/

#ifndef SERVER_SRC_SERVER_SERVER_SIGNAL_H
#define SERVER_SRC_SERVER_SERVER_SIGNAL_H

#include <select.h>
#include <signal.h>

typedef struct sigaction sigaction_t;

int server_signal_get(int value);
timeval_t *server_signal_timeval(int sec, int usec);
int server_signal_init(void);

#endif // SERVER_SRC_SERVER_SERVER_SIGNAL_H
