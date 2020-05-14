/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_list_xml.c
*/

#define _GNU_SOURCE

#include "channel_list_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "channel_xml.h"
#include "def/code.h"

channel_list_t *channel_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *channel_list_xml_export(const channel_list_t *channel_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<channels>\n") == CODE_INVALID)
        return (NULL);

    for (channel_node_t *node = channel_list->begin; node; node = node->next) {
        char *tmp = xml;
        char *channel_xml = channel_xml_export(node->channel);

        if (asprintf(&xml, "%s%s\n", xml, channel_xml) == CODE_INVALID)
            return (NULL);

        free(channel_xml);
        free(tmp);
    }

    char *tmp = xml;

    if (asprintf(&xml, "%s</channels>", xml) == CODE_INVALID)
        return (NULL);

    free(tmp);

    return (xml);
}
