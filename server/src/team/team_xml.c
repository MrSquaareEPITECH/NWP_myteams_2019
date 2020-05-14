/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_xml.c
*/

#define _GNU_SOURCE

#include "team_xml.h"

#include <malloc.h>
#include <stdio.h>

#include "channel/channel_list_xml.h"
#include "def/code.h"
#include "subscriber/subscriber_list_xml.h"

team_t *team_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *team_xml_export(const team_t *team)
{
    char *xml = NULL;
    char *channels_xml = channel_list_xml_export(team->channels);
    char *subscribers_xml = subscriber_list_xml_export(team->subscribers);

    if (asprintf(&xml,
            "<team id=\"%s\" name=\"%s\" description=\"%s\">\n"
            "%s\n%s\n</team>",
            team->uuid, team->name, team->description, channels_xml,
            subscribers_xml) == CODE_INVALID)
        return (NULL);

    free(channels_xml);
    free(subscribers_xml);

    return (xml);
}
