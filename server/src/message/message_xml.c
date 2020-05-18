/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_xml.c
*/

#define _GNU_SOURCE

#include "message_xml.h"

#include <stdio.h>
#include <string.h>

#include "def/cast.h"

message_t *message_xml_import(xmlNodePtr node)
{
    message_t *message = malloc(sizeof(message_t));

    message->timestamp =
        strtol(GOOD_CAST xmlGetProp(node, BAD_CAST "timestamp"), NULL, 10);
    memset(message->body, 0, sizeof(message->body));
    strncpy(message->body, GOOD_CAST xmlNodeGetContent(node), UUID_LENGTH);
    return (message);
}

xmlNodePtr message_xml_export(const message_t *message, xmlNodePtr parent)
{
    xmlNodePtr child = xmlNewTextChild(
        parent, NULL, BAD_CAST "message", BAD_CAST message->body);
    char *timestamp = NULL;

    asprintf(&timestamp, "%ld", message->timestamp);
    xmlSetProp(child, BAD_CAST "timestamp", BAD_CAST timestamp);
    xmlAddChild(parent, child);
    free(timestamp);
    return (child);
}
