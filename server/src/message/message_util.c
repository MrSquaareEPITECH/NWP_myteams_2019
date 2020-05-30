/*
** EPITECH PROJECT, 2020
** server
** File description:
** message_util.c
*/

#include "message_util.h"

#include "def/data.h"
#include "util/string.h"

char *message_to_data(message_t *message)
{
    char *data =
        strfmt(DATA_MESSAGE, message->user, message->timestamp, message->body);

    return (data);
}
