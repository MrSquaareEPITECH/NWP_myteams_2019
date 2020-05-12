/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber_list_xml.c
*/

#define _GNU_SOURCE

#include "subscriber_list_xml.h"

#include <stdio.h>

#include "def/code.h"
#include "subscriber_xml.h"

subscriber_list_t *subscriber_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *subscriber_list_xml_export(const subscriber_list_t *subscriber_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<subscribers>\n") == CODE_INVALID)
        return (NULL);

    for (subscriber_node_t *node = subscriber_list->begin; node;
         node = node->next)
        if (asprintf(&xml,
                "%s"
                "%s\n",
                xml, subscriber_xml_export(node->subscriber)) == CODE_INVALID)
            return (NULL);

    if (asprintf(&xml,
            "%s"
            "</subscribers>",
            xml) == CODE_INVALID)
        return (NULL);

    return (xml);
}
