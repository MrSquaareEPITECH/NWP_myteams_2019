/*
** EPITECH PROJECT, 2020
** cli
** File description:
** login.c
*/

#include <logging_client.h>

#include "client/client_internal.h"
#include "def/code.h"
#include "subresponse.h"

int user_loggedin_subresponse(client_t *client, int argc, char **argv)
{
    (void)(argc);
    (void)(argv);

    int argcr = 0;
    char **argvr = 0;

    if (client_receive(client, &argcr, &argvr) == CODE_ERROR)
        return (CODE_ERROR);
    client_event_loggedin(argvr[0], argvr[1]);
    return (CODE_SUCCESS);
}
