/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_xml.c
*/

#define _GNU_SOURCE

#include "channel_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "def/code.h"
#include "thread/thread_list_xml.h"

channel_t *channel_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *channel_xml_export(const channel_t *channel)
{
    char *xml = NULL;
    char *threads_xml = thread_list_xml_export(channel->threads);

    if (asprintf(&xml,
            "<channel id=\"%s\" name=\"%s\" description=\"%s\">\n"
            "%s\n</channel>",
            channel->uuid, channel->name, channel->description,
            threads_xml) == CODE_INVALID)
        return (NULL);

    free(threads_xml);

    return (xml);
}
