/*
** EPITECH PROJECT, 2020
** server
** File description:
** server_signal.c
*/

#include "server_signal.h"

#include <memory.h>
#include <stdio.h>

#include "def/code.h"

static void server_signal_handler(int signal, siginfo_t *info, void *context)
{
    (void)(signal);
    (void)(info);
    (void)(context);

    server_signal_get(signal);
    server_signal_timeval(0, 0);
}

int server_signal_get(int value)
{
    static int signal = 0;

    if (value != -1)
        signal = value;
    return (signal);
}

timeval_t *server_signal_timeval(int sec, int usec)
{
    static timeval_t timeval;

    if (sec != -1)
        timeval.tv_sec = sec;
    if (usec != -1)
        timeval.tv_usec = usec;
    return (&timeval);
}

int server_signal_init(void)
{
    sigaction_t action;

    memset(&action, 0, sizeof(sigaction_t));
    action.sa_sigaction = &server_signal_handler;

    if (sigaction(SIGINT, &action, NULL) == CODE_INVALID)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
