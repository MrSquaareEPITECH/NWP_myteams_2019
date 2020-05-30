/*
** EPITECH PROJECT, 2020
** server
** File description:
** exchange_xml.c
*/

#include "exchange_xml.h"

#include <stdlib.h>
#include <string.h>

#include "list/list_xml.h"
#include "message/message_xml.h"
#include "util/string.h"
#include "xml/xml_attribute.h"

exchange_t *exchange_xml_import(xml_element_t *element)
{
    exchange_t *exchange = malloc(sizeof(exchange_t));
    char *uuid = xml_attributes_get(element->attributes, "id");
    xml_element_t *messages = xml_element_get(element->children, "messages");

    memset(exchange->uuid, 0, UUID_LENGTH + 1);
    strncpy(exchange->uuid, uuid, UUID_LENGTH);
    exchange->messages =
        list_xml_import(messages, (import_t)(message_xml_import));
    return (exchange);
}

char *exchange_xml_export(exchange_t *exchange)
{
    char *messages_xml = list_xml_export(
        exchange->messages, "\t\t", "messages", (export_t)(message_xml_export));
    char *xml = strfmt("\t<exchange id=\"%s\">\n%s\n\t</exchange>",
        exchange->uuid, messages_xml);

    free(messages_xml);
    return (xml);
}
