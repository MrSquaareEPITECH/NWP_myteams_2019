/*
** EPITECH PROJECT, 2020
** server
** File description:
** team_xml.c
*/

#include "team_xml.h"

#include <stdlib.h>
#include <string.h>

#include "channel/channel_xml.h"
#include "list/list_xml.h"
#include "subscriber/subscriber_xml.h"
#include "util/string.h"
#include "xml/xml_attribute.h"

team_t *team_xml_import(xml_element_t *element)
{
    team_t *team = malloc(sizeof(team_t));
    char *uuid = xml_attributes_get(element->attributes, "id");
    char *name = xml_attributes_get(element->attributes, "name");
    char *description = xml_attributes_get(element->attributes, "description");
    xml_element_t *channels = xml_element_get(element->children, "channels");
    xml_element_t *subscribers =
        xml_element_get(element->children, "subscribers");

    memset(team->uuid, 0, UUID_LENGTH + 1);
    strncpy(team->uuid, uuid, UUID_LENGTH);
    memset(team->name, 0, MAX_NAME_LENGTH + 1);
    strncpy(team->name, name, MAX_NAME_LENGTH);
    memset(team->description, 0, MAX_DESCRIPTION_LENGTH + 1);
    strncpy(team->description, description, MAX_DESCRIPTION_LENGTH);
    team->channels =
        list_xml_import_p(channels, (import_p_t)(channel_xml_import), team);
    team->subscribers =
        list_xml_import(subscribers, (import_t)(subscriber_xml_import));
    return (team);
}

char *team_xml_export(team_t *team)
{
    char *channels_xml = list_xml_export(
        team->channels, "\t\t", "channels", (export_t)(channel_xml_export));
    char *subscribers_xml = list_xml_export(team->subscribers, "\t\t",
        "subscribers", (export_t)(subscriber_xml_export));
    char *xml = strfmt(
        "\t<team id=\"%s\" name=\"%s\" "
        "description=\"%s\">\n%s\n%s\n\t</team>",
        team->uuid, team->name, team->description, channels_xml,
        subscribers_xml);

    free(subscribers_xml);
    free(channels_xml);
    return (xml);
}
