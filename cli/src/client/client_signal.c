/*
** EPITECH PROJECT, 2020
** cli
** File description:
** client_signal.c
*/

#include "client_signal.h"

#include <memory.h>

#include "def/code.h"

static void client_signal_handler(int signal, siginfo_t *info, void *context)
{
    (void)(signal);
    (void)(info);
    (void)(context);

    client_signal_get(signal);
    client_signal_timeval(0, 0);
}

int client_signal_get(int value)
{
    static int signal = 0;

    if (value != -1)
        signal = value;
    return (signal);
}

timeval_t *client_signal_timeval(int sec, int usec)
{
    static timeval_t timeval;

    if (sec != -1)
        timeval.tv_sec = sec;
    if (usec != -1)
        timeval.tv_usec = usec;
    return (&timeval);
}

int client_signal_init(void)
{
    sigaction_t action;

    memset(&action, 0, sizeof(sigaction_t));
    action.sa_sigaction = &client_signal_handler;

    if (sigaction(SIGINT, &action, NULL) == CODE_INVALID)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
