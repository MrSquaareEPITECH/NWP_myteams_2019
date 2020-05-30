/*
** EPITECH PROJECT, 2020
** server
** File description:
** thread_xml.c
*/

#include "thread_xml.h"

#include <stdlib.h>
#include <string.h>

#include "comment/comment_xml.h"
#include "list/list_xml.h"
#include "util/string.h"
#include "xml/xml_attribute.h"

static void thread_xml_import_content(thread_t *thread, xml_element_t *element)
{
    xml_element_t *body = xml_element_get(element->children, "body");
    xml_element_t *comments = xml_element_get(element->children, "comments");

    memset(thread->body, 0, MAX_BODY_LENGTH + 1);
    strncpy(thread->body, body->content, MAX_BODY_LENGTH);
    thread->comments =
        list_xml_import_p(comments, (import_p_t)(comment_xml_import), thread);
}

static char *thread_xml_export_body(thread_t *thread)
{
    char *xml = strfmt("\t\t\t\t\t\t<body>%s</body>", thread->body);

    return (xml);
}

thread_t *thread_xml_import(channel_t *parent, xml_element_t *element)
{
    thread_t *thread = malloc(sizeof(thread_t));
    char *uuid = xml_attributes_get(element->attributes, "id");
    char *user = xml_attributes_get(element->attributes, "user");
    char *timestamp = xml_attributes_get(element->attributes, "timestamp");
    char *name = xml_attributes_get(element->attributes, "name");

    memset(thread->uuid, 0, UUID_LENGTH + 1);
    strncpy(thread->uuid, uuid, UUID_LENGTH);
    memset(thread->user, 0, UUID_LENGTH + 1);
    strncpy(thread->user, user, UUID_LENGTH);
    thread->timestamp = strtol(timestamp, NULL, 10);
    memset(thread->name, 0, MAX_NAME_LENGTH + 1);
    strncpy(thread->name, name, MAX_NAME_LENGTH);
    thread_xml_import_content(thread, element);
    thread->parent = parent;
    return (thread);
}

char *thread_xml_export(thread_t *thread)
{
    char *body_xml = thread_xml_export_body(thread);
    char *comments_xml = list_xml_export(thread->comments, "\t\t\t\t\t\t",
        "comments", (export_t)(comment_xml_export));
    char *xml = strfmt(
        "\t\t\t\t\t<thread id=\"%s\" user=\"%s\" timestamp=\"%ld\" "
        "name=\"%s\">\n%s\n%s\n\t\t\t\t\t</thread>",
        thread->uuid, thread->user, thread->timestamp, thread->name, body_xml,
        comments_xml);

    free(comments_xml);
    free(body_xml);
    return (xml);
}
