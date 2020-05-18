/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_xml.c
*/

#include "team_xml.h"

#include <string.h>

#include "channel/channel_xml.h"
#include "def/cast.h"
#include "list/list_xml.h"
#include "subscriber/subscriber_xml.h"
#include "util/xml.h"

team_t *team_xml_import(xmlNodePtr node)
{
    team_t *team = malloc(sizeof(team_t));
    char *id = GOOD_CAST xmlGetProp(node, BAD_CAST "id");
    char *name = GOOD_CAST xmlGetProp(node, BAD_CAST "name");
    char *description = GOOD_CAST xmlGetProp(node, BAD_CAST "description");
    xmlNodePtr channels = xml_get_child(node, BAD_CAST "channels");
    xmlNodePtr subscribers = xml_get_child(node, BAD_CAST "subscribers");

    if (!team || !id || !name || !description || !channels)
        return (NULL);
    memset(team->uuid, 0, sizeof(team->uuid));
    strncpy(team->uuid, id, UUID_LENGTH);
    memset(team->name, 0, sizeof(team->name));
    strncpy(team->name, name, MAX_NAME_LENGTH);
    memset(team->description, 0, sizeof(team->description));
    strncpy(team->description, description, MAX_DESCRIPTION_LENGTH);
    team->channels =
        list_xml_import(channels, "channel", import_c(channel_xml_import));
    team->subscribers = list_xml_import(
        subscribers, "subscriber", import_c(subscriber_xml_import));
    return (team);
}

xmlNodePtr team_xml_export(const team_t *team, xmlNodePtr parent)
{
    xmlNodePtr child = xmlNewTextChild(parent, NULL, BAD_CAST "team", NULL);
    xmlNodePtr channels =
        xmlNewTextChild(child, NULL, BAD_CAST "channels", NULL);
    xmlNodePtr subscribers =
        xmlNewTextChild(child, NULL, BAD_CAST "subscribers", NULL);

    channels =
        list_xml_export(team->channels, channels, export_c(channel_xml_export));
    subscribers = list_xml_export(
        team->subscribers, subscribers, export_c(subscriber_xml_export));
    xmlSetProp(child, BAD_CAST "id", BAD_CAST team->uuid);
    xmlSetProp(child, BAD_CAST "name", BAD_CAST team->name);
    xmlSetProp(child, BAD_CAST "description", BAD_CAST team->description);
    xmlAddChild(child, channels);
    xmlAddChild(child, subscribers);
    xmlAddChild(parent, child);
    return (child);
}
