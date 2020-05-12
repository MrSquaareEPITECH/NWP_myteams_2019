/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_list_xml.c
*/

#define _GNU_SOURCE

#include "message_list_xml.h"

#include <stdio.h>

#include "def/code.h"
#include "message_xml.h"

message_list_t *message_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *message_list_xml_export(const message_list_t *message_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<messages>\n") == CODE_INVALID)
        return (NULL);

    for (message_node_t *node = message_list->begin; node; node = node->next)
        if (asprintf(&xml,
                "%s"
                "%s\n",
                xml, message_xml_export(node->message)) == CODE_INVALID)
            return (NULL);

    if (asprintf(&xml,
            "%s"
            "</messages>",
            xml) == CODE_INVALID)
        return (NULL);

    return (xml);
}
