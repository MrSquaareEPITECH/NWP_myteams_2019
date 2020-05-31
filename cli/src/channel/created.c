/*
** EPITECH PROJECT, 2020
** cli
** File description:
** created.c
*/

#include <logging_client.h>

#include "client/client_internal.h"
#include "def/code.h"
#include "subresponse.h"

int channel_created_subresponse(client_t *client, int argc, char **argv)
{
    (void)(argc);
    (void)(argv);

    int argcr = 0;
    char **argvr = 0;

    if (client_receive(client, &argcr, &argvr) == CODE_ERROR)
        return (CODE_ERROR);
    client_event_channel_created(argvr[0], argvr[1], argvr[2]);
    return (CODE_SUCCESS);
}
