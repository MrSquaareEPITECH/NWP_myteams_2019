/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_xml.c
*/

#define _GNU_SOURCE

#include "channel_xml.h"

#include <stdio.h>
#include <regex.h>

#include "def/code.h"
#include "thread/thread_list_xml.h"

channel_t *channel_xml_import(const char *xml)
{

}

char *channel_xml_export(const channel_t *channel)
{
    char *xml = NULL;

    if (asprintf(&xml,
            "<channel id=\"%s\" name=\"%s\" description=\"%s\">\n"
            "%s\n"
            "</channel>",
            channel->uuid, channel->name, channel->description,
            thread_list_xml_export(channel->threads)) == CODE_INVALID)
        return (NULL);

    return (xml);
}
