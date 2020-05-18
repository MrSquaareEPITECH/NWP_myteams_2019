/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_xml.c
*/

#include "channel_xml.h"

#include <string.h>

#include "def/cast.h"
#include "list/list_xml.h"
#include "thread/thread_xml.h"
#include "util/xml.h"

channel_t *channel_xml_import(xmlNodePtr node)
{
    channel_t *channel = malloc(sizeof(channel_t));
    char *id = GOOD_CAST xmlGetProp(node, BAD_CAST "id");
    char *name = GOOD_CAST xmlGetProp(node, BAD_CAST "name");
    char *description = GOOD_CAST xmlGetProp(node, BAD_CAST "description");
    xmlNodePtr threads = xml_get_child(node, BAD_CAST "threads");

    if (!channel || !id || !name || !description || !threads)
        return (NULL);
    memset(channel->uuid, 0, sizeof(channel->uuid));
    strncpy(channel->uuid, id, UUID_LENGTH);
    memset(channel->name, 0, sizeof(channel->name));
    strncpy(channel->name, name, MAX_NAME_LENGTH);
    memset(channel->description, 0, sizeof(channel->description));
    strncpy(channel->description, description, MAX_DESCRIPTION_LENGTH);
    channel->threads =
        list_xml_import(threads, "thread", import_c(thread_xml_import));
    return (channel);
}

xmlNodePtr channel_xml_export(const channel_t *channel, xmlNodePtr parent)
{
    xmlNodePtr child = xmlNewTextChild(parent, NULL, BAD_CAST "channel", NULL);
    xmlNodePtr threads = xmlNewTextChild(child, NULL, BAD_CAST "threads", NULL);

    threads =
        list_xml_export(channel->threads, threads, export_c(thread_xml_export));
    xmlSetProp(child, BAD_CAST "id", BAD_CAST channel->uuid);
    xmlSetProp(child, BAD_CAST "name", BAD_CAST channel->name);
    xmlSetProp(child, BAD_CAST "description", BAD_CAST channel->description);
    xmlAddChild(child, threads);
    xmlAddChild(parent, child);
    return (child);
}
