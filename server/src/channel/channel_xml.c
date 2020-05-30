/*
** EPITECH PROJECT, 2020
** server
** File description:
** channel_xml.c
*/

#include "channel_xml.h"

#include <stdlib.h>
#include <string.h>

#include "list/list_xml.h"
#include "thread/thread_xml.h"
#include "util/string.h"
#include "xml/xml_attribute.h"

channel_t *channel_xml_import(team_t *parent, xml_element_t *element)
{
    channel_t *channel = malloc(sizeof(channel_t));
    char *uuid = xml_attributes_get(element->attributes, "id");
    char *name = xml_attributes_get(element->attributes, "name");
    char *description = xml_attributes_get(element->attributes, "description");
    xml_element_t *threads = xml_element_get(element->children, "threads");

    memset(channel->uuid, 0, UUID_LENGTH + 1);
    strncpy(channel->uuid, uuid, UUID_LENGTH);
    memset(channel->name, 0, MAX_NAME_LENGTH + 1);
    strncpy(channel->name, name, MAX_NAME_LENGTH);
    memset(channel->description, 0, MAX_DESCRIPTION_LENGTH + 1);
    strncpy(channel->description, description, MAX_DESCRIPTION_LENGTH);
    channel->threads =
        list_xml_import_p(threads, (import_p_t)(thread_xml_import), channel);
    channel->parent = parent;
    return (channel);
}

char *channel_xml_export(channel_t *channel)
{
    char *threads_xml = list_xml_export(
        channel->threads, "\t\t\t\t", "threads", (export_t)(thread_xml_export));
    char *xml = strfmt(
        "\t\t\t<channel id=\"%s\" name=\"%s\" "
        "description=\"%s\">\n%s\n\t\t\t</channel>",
        channel->uuid, channel->name, channel->description, threads_xml);

    free(threads_xml);
    return (xml);
}
