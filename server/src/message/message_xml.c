/*
** EPITECH PROJECT, 2020
** server
** File description:
** message_xml.c
*/

#include "message_xml.h"

#include <stdlib.h>
#include <string.h>

#include "util/string.h"
#include "xml/xml_attribute.h"

message_t *message_xml_import(xml_element_t *element)
{
    message_t *message = malloc(sizeof(message_t));
    char *user = xml_attributes_get(element->attributes, "user");
    char *timestamp = xml_attributes_get(element->attributes, "timestamp");

    memset(message->user, 0, sizeof(message->user));
    strncpy(message->user, user, UUID_LENGTH);
    message->timestamp = strtol(timestamp, NULL, 10);
    memset(message->body, 0, sizeof(message->body));
    strncpy(message->body, element->content, MAX_BODY_LENGTH);
    return (message);
}

char *message_xml_export(message_t *message)
{
    char *xml =
        strfmt("\t\t\t<message user=\"%s\" timestamp=\"%ld\">%s</message>",
            message->user, message->timestamp, message->body);

    return (xml);
}
