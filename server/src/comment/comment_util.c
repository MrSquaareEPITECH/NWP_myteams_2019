/*
** EPITECH PROJECT, 2020
** server
** File description:
** comment_util.c
*/

#include "comment_util.h"

#include "def/data.h"
#include "util/string.h"

char *comment_to_data(comment_t *comment)
{
    char *data = strfmt(DATA_COMMENT, comment->timestamp, comment->body);

    return (data);
}
