/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_xml.c
*/

#define _GNU_SOURCE

#include "private_xml.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def/code.h"
#include "message/message_list_xml.h"

private_t *private_xml_import(xml_element_t *element)
{
    private_t *private = malloc(sizeof(private_t));

    memset(private->uuid, 0, UUID_LENGTH + 1);
    strncpy(private->uuid, element->attributes[0]->value, UUID_LENGTH);

    xml_element_t *messages_element = xml_element_create(element->content);
    private->messages = message_list_xml_import(messages_element);
    xml_element_delete(messages_element);

    return (private);
}

private_t *private_xml_libxml2_import(xmlNodePtr node)
{
    private_t *private = malloc(sizeof(private_t));

    memset(private->uuid, 0, UUID_LENGTH + 1);
    strncpy(private->uuid, node->properties->children->content, UUID_LENGTH);

    for (xmlNodePtr child = node->children; child; child = child->next)
        if (xmlStrcmp(child->name, "messages") == 0)
            private->messages = message_list_xml_libxml2_import(child);

    return (private);
}

char *private_xml_export(const private_t *private)
{
    char *xml = NULL;
    char *messages_xml = message_list_xml_export(private->messages);

    if (asprintf(&xml, "\t\t\t<private id=\"%s\">\n%s\n\t\t\t</private>", private->uuid,
            messages_xml) == CODE_INVALID)
        return (NULL);

    free(messages_xml);

    return (xml);
}