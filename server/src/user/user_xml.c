/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_xml.c
*/

#define _GNU_SOURCE

#include "user_xml.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def/code.h"
#include "private/private_list_xml.h"

user_t *user_xml_import(xml_element_t *element)
{
    user_t *user = malloc(sizeof(user_t));

    memset(user->uuid, 0, UUID_LENGTH + 1);
    strncpy(user->uuid, element->attributes[0]->value, UUID_LENGTH);
    memset(user->name, 0, MAX_NAME_LENGTH + 1);
    strncpy(user->name, element->attributes[1]->value, MAX_NAME_LENGTH);

    xml_element_t *privates_element = xml_element_create(element->content);
    user->privates = private_list_xml_import(privates_element);
    xml_element_delete(privates_element);

    return (user);
}

user_t *user_xml_libxml2_import(xmlNodePtr node)
{
    user_t *user = malloc(sizeof(user_t));

    memset(user->uuid, 0, UUID_LENGTH + 1);
    strncpy(user->uuid, node->properties->children->content, UUID_LENGTH);
    memset(user->name, 0, MAX_NAME_LENGTH + 1);
    strncpy(user->name, node->properties->next->children->content, MAX_NAME_LENGTH);

    for (xmlNodePtr child = node->children; child; child = child->next)
        if (xmlStrcmp(child->name, "privates") == 0)
            user->privates = private_list_xml_libxml2_import(child);

    return (user);
}

char *user_xml_export(const user_t *user)
{
    char *xml = NULL;
    char *privates_xml = private_list_xml_export(user->privates);

    if (asprintf(&xml,
            "\t<user id=\"%s\" name=\"%s\">\n"
            "%s\n\t</user>",
            user->uuid, user->name, privates_xml) == CODE_INVALID)
        return (NULL);

    free(privates_xml);

    return (xml);
}
