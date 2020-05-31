/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscriber_xml.c
*/

#include "subscriber_xml.h"

#include <stdlib.h>
#include <string.h>

#include "util/string.h"
#include "xml/xml_attribute.h"

subscriber_t *subscriber_xml_import(xml_element_t *element)
{
    subscriber_t *subscriber = malloc(sizeof(subscriber_t));
    char *uuid = xml_attributes_get(element->attributes, "id");

    memset(subscriber->uuid, 0, sizeof(subscriber->uuid));
    strncpy(subscriber->uuid, uuid, UUID_LENGTH);
    return (subscriber);
}

char *subscriber_xml_export(subscriber_t *subscriber)
{
    char *xml =
        strfmt("\t\t\t<subscriber id=\"%s\"></subscriber>", subscriber->uuid);

    return (xml);
}
