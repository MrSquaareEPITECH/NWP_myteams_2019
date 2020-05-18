/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_xml.c
*/

#include "private_xml.h"

#include <string.h>

#include "def/cast.h"
#include "list/list_xml.h"
#include "message/message_xml.h"

private_t *private_xml_import(xmlNodePtr node)
{
    private_t *private = malloc(sizeof(private_t));

    memset(private->uuid, 0, sizeof(private->uuid));
    strncpy(
        private->uuid, GOOD_CAST xmlGetProp(node, BAD_CAST "id"), UUID_LENGTH);
    for (xmlNodePtr child = node->children; child; child = child->next)
        if (xmlStrcmp(child->name, BAD_CAST "messages") == 0)
            private->messages = list_xml_import(child, "message", import_c(message_xml_import));
    return (private);
}

xmlNodePtr private_xml_export(const private_t *private, xmlNodePtr parent)
{
    xmlNodePtr child = xmlNewTextChild(parent, NULL, BAD_CAST "private", NULL);
    xmlNodePtr messages =
        xmlNewTextChild(child, NULL, BAD_CAST "messages", NULL);

    messages = list_xml_export(
        private->messages, messages, export_c(message_xml_export));
    xmlSetProp(child, BAD_CAST "id", BAD_CAST private->uuid);
    xmlAddChild(child, messages);
    xmlAddChild(parent, child);
    return (child);
}
