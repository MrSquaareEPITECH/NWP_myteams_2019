/*
** EPITECH PROJECT, 2020
** server
** File description:
** user_xml.c
*/

#include "user_xml.h"

#include <logging_server.h>
#include <stdlib.h>
#include <string.h>

#include "list/list_xml.h"
#include "private/private_xml.h"
#include "util/string.h"
#include "xml/xml_attribute.h"

user_t *user_xml_import(xml_element_t *element)
{
    user_t *user = malloc(sizeof(user_t));
    char *uuid = xml_attributes_get(element->attributes, "id");
    char *name = xml_attributes_get(element->attributes, "name");
    xml_element_t *privates = xml_element_get(element->children, "privates");

    memset(user->uuid, 0, UUID_LENGTH + 1);
    strncpy(user->uuid, uuid, UUID_LENGTH);
    memset(user->name, 0, MAX_NAME_LENGTH + 1);
    strncpy(user->name, name, MAX_NAME_LENGTH);
    user->status = 0;
    user->privates = list_xml_import(privates, (import_t)(private_xml_import));
    user->use = USE_SERVER;
    user->obj = NULL;
    server_event_user_loaded(user->uuid, user->name);
    return (user);
}

char *user_xml_export(user_t *user)
{
    char *privates_xml = list_xml_export(
        user->privates, "\t\t", "privates", (export_t)(private_xml_export));
    char *xml = strfmt("\t<user id=\"%s\" name=\"%s\">\n%s\n\t</user>",
        user->uuid, user->name, privates_xml);

    free(privates_xml);
    return (xml);
}
