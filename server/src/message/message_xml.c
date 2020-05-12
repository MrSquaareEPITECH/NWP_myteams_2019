/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_xml.c
*/

#define _GNU_SOURCE

#include "message_xml.h"

#include <stdio.h>

#include "def/code.h"

message_t *message_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *message_xml_export(const message_t *message)
{
    char *xml = NULL;

    if (asprintf(&xml, "\"%ld\" \"%s\"", message->timestamp, message->body) ==
        CODE_INVALID)
        return (NULL);

    return (xml);
}
