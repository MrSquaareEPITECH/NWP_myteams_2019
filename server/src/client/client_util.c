/*
** EPITECH PROJECT, 2020
** server
** File description:
** client_util.c
*/

#include "client_util.h"

#include "def/code.h"

int client_reply(client_t *client, char *response, char *data)
{
    if (list_push(client->queue, response) == CODE_ERROR)
        return (CODE_ERROR);
    if (list_push(client->queue, data) == CODE_ERROR)
        return (CODE_ERROR);
    return (CODE_SUCCESS);
}
