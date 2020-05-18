/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment_xml.c
*/

#define _GNU_SOURCE

#include "comment_xml.h"

#include <stdio.h>
#include <string.h>

#include "def/cast.h"

comment_t *comment_xml_import(xmlNodePtr node)
{
    comment_t *comment = malloc(sizeof(comment_t));
    char *timestamp = GOOD_CAST xmlGetProp(node, BAD_CAST "timestamp");

    if (!comment || !timestamp)
        return (NULL);
    comment->timestamp = strtol(timestamp, NULL, 10);
    memset(comment->body, 0, sizeof(comment->body));
    strncpy(comment->body, GOOD_CAST xmlNodeGetContent(node), UUID_LENGTH);
    return (comment);
}

xmlNodePtr comment_xml_export(const comment_t *comment, xmlNodePtr parent)
{
    xmlNodePtr child = xmlNewTextChild(
        parent, NULL, BAD_CAST "comment", BAD_CAST comment->body);
    char *timestamp = NULL;

    asprintf(&timestamp, "%ld", comment->timestamp);
    xmlSetProp(child, BAD_CAST "timestamp", BAD_CAST timestamp);
    xmlAddChild(parent, child);
    free(timestamp);
    return (child);
}
