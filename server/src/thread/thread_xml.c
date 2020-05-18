/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_xml.c
*/

#define _GNU_SOURCE

#include "thread_xml.h"

#include <stdio.h>
#include <string.h>

#include "comment/comment_xml.h"
#include "def/cast.h"
#include "list/list_xml.h"
#include "util/xml.h"

thread_t *thread_xml_import(xmlNodePtr node)
{
    thread_t *thread = malloc(sizeof(thread_t));
    char *id = GOOD_CAST xmlGetProp(node, BAD_CAST "id");
    char *timestamp = GOOD_CAST xmlGetProp(node, BAD_CAST "timestamp");
    char *name = GOOD_CAST xmlGetProp(node, BAD_CAST "name");
    xmlNodePtr body = xml_get_child(node, BAD_CAST "body");
    xmlNodePtr comments = xml_get_child(node, BAD_CAST "comments");

    if (!thread || !id || !timestamp || !name || !body || !comments)
        return (NULL);
    memset(thread->uuid, 0, sizeof(thread->uuid));
    strncpy(thread->uuid, id, UUID_LENGTH);
    thread->timestamp = strtol(timestamp, NULL, 10);
    memset(thread->name, 0, sizeof(thread->name));
    strncpy(thread->name, name, MAX_NAME_LENGTH);
    memset(thread->body, 0, sizeof(thread->body));
    strncpy(thread->body, GOOD_CAST xmlNodeGetContent(body), MAX_BODY_LENGTH);
    thread->comments =
        list_xml_import(comments, "comment", import_c(comment_xml_import));
    return (thread);
}

xmlNodePtr thread_xml_export(const thread_t *thread, xmlNodePtr parent)
{
    xmlNodePtr child = xmlNewTextChild(parent, NULL, BAD_CAST "thread", NULL);
    xmlNodePtr body =
        xmlNewTextChild(child, NULL, BAD_CAST "body", BAD_CAST thread->body);
    xmlNodePtr comments =
        xmlNewTextChild(child, NULL, BAD_CAST "comments", NULL);
    char *timestamp = NULL;

    asprintf(&timestamp, "%ld", thread->timestamp);
    comments = list_xml_export(
        thread->comments, comments, export_c(comment_xml_export));
    xmlSetProp(child, BAD_CAST "id", BAD_CAST thread->uuid);
    xmlSetProp(child, BAD_CAST "timestamp", BAD_CAST timestamp);
    xmlSetProp(child, BAD_CAST "name", BAD_CAST thread->name);
    xmlAddChild(child, body);
    xmlAddChild(child, comments);
    xmlAddChild(parent, child);
    free(timestamp);
    return (child);
}
