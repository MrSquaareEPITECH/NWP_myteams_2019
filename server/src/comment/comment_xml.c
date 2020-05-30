/*
** EPITECH PROJECT, 2020
** server
** File description:
** comment_xml.c
*/

#include "comment_xml.h"

#include <stdlib.h>
#include <string.h>

#include "util/string.h"
#include "xml/xml_attribute.h"

comment_t *comment_xml_import(thread_t *parent, xml_element_t *element)
{
    comment_t *comment = malloc(sizeof(comment_t));
    char *user = xml_attributes_get(element->attributes, "user");
    char *timestamp = xml_attributes_get(element->attributes, "timestamp");

    memset(comment->user, 0, sizeof(comment->user));
    strncpy(comment->user, user, UUID_LENGTH);
    comment->timestamp = strtol(timestamp, NULL, 10);
    memset(comment->body, 0, sizeof(comment->body));
    strncpy(comment->body, element->content, MAX_BODY_LENGTH);
    comment->parent = parent;
    return (comment);
}

char *comment_xml_export(comment_t *comment)
{
    char *xml = strfmt(
        "\t\t\t\t\t\t\t<comment user=\"%s\" timestamp=\"%ld\">%s</comment>",
        comment->user, comment->timestamp, comment->body);

    return (xml);
}
