/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_xml.c
*/

#define _GNU_SOURCE

#include "private_xml.h"

#include <stdio.h>

#include "def/code.h"
#include "message/message_list_xml.h"

private_t *private_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *private_xml_export(const private_t *private)
{
    char *xml = NULL;

    if (asprintf(&xml,
            "<private id=\"%s\">\n"
            "%s\n"
            "</private>",
            private->uuid,
            message_list_xml_export(private->messages)) == CODE_INVALID)
        return (NULL);

    return (xml);
}
