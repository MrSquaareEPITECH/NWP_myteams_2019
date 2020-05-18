/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber_xml.c
*/

#include "subscriber_xml.h"

#include <string.h>

#include "def/cast.h"

subscriber_t *subscriber_xml_import(xmlNodePtr node)
{
    subscriber_t *subscriber = malloc(sizeof(subscriber_t));
    char *id = GOOD_CAST xmlGetProp(node, BAD_CAST "id");

    if (!subscriber || !id)
        return (NULL);
    memset(subscriber->uuid, 0, sizeof(subscriber->uuid));
    strncpy(subscriber->uuid, id, UUID_LENGTH);
    return (subscriber);
}

xmlNodePtr subscriber_xml_export(
    const subscriber_t *subscriber, xmlNodePtr parent)
{
    xmlNodePtr child =
        xmlNewTextChild(parent, NULL, BAD_CAST "subscriber", NULL);

    xmlSetProp(child, BAD_CAST "id", BAD_CAST subscriber->uuid);
    xmlAddChild(parent, child);
    return (child);
}
