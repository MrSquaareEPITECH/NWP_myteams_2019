/*
** EPITECH PROJECT, 2020
** cli
** File description:
** client_signal.h
*/

#ifndef CLI_SRC_CLIENT_CLIENT_SIGNAL_H
#define CLI_SRC_CLIENT_CLIENT_SIGNAL_H

#include <select.h>
#include <signal.h>

typedef struct sigaction sigaction_t;

int client_signal_get(int value);
timeval_t *client_signal_timeval(int sec, int usec);
int client_signal_init(void);

#endif // CLI_SRC_CLIENT_CLIENT_SIGNAL_H
