/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_list_xml.c
*/

#define _GNU_SOURCE

#include "channel_list_xml.h"

#include <stdio.h>

#include "channel_xml.h"
#include "def/code.h"

channel_list_t *channel_list_xml_import(const char *xml)
{
}

char *channel_list_xml_export(const channel_list_t *channel_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<channels>\n") == CODE_INVALID)
        return (NULL);

    for (channel_node_t *node = channel_list->begin; node; node = node->next)
        if (asprintf(&xml,
                "%s"
                "%s\n",
                xml, channel_xml_export(node->channel)) == CODE_INVALID)
            return (NULL);

    if (asprintf(&xml,
            "%s"
            "</channels>",
            xml) == CODE_INVALID)
        return (NULL);

    return (xml);
}
