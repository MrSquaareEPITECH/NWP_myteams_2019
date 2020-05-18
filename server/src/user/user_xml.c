/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_xml.c
*/

#include "user_xml.h"

#include <string.h>

#include "def/cast.h"
#include "list/list_xml.h"
#include "private/private_xml.h"

user_t *user_xml_import(xmlNodePtr node)
{
    user_t *user = malloc(sizeof(user_t));

    memset(user->uuid, 0, sizeof(user->uuid));
    strncpy(user->uuid, GOOD_CAST xmlGetProp(node, BAD_CAST "id"), UUID_LENGTH);
    memset(user->name, 0, sizeof(user->name));
    strncpy(user->name, GOOD_CAST xmlGetProp(node, BAD_CAST "name"),
        MAX_NAME_LENGTH);
    for (xmlNodePtr child = node->children; child; child = child->next)
        if (xmlStrcmp(child->name, BAD_CAST "privates") == 0)
            user->privates =
                list_xml_import(child, "private", import_c(private_xml_import));
    return (user);
}

xmlNodePtr user_xml_export(const user_t *user, xmlNodePtr parent)
{
    xmlNodePtr child = xmlNewTextChild(parent, NULL, BAD_CAST "user", NULL);
    xmlNodePtr privates =
        xmlNewTextChild(child, NULL, BAD_CAST "privates", NULL);

    privates =
        list_xml_export(user->privates, privates, export_c(private_xml_export));
    xmlSetProp(child, BAD_CAST "id", BAD_CAST user->uuid);
    xmlSetProp(child, BAD_CAST "name", BAD_CAST user->name);
    xmlAddChild(child, privates);
    xmlAddChild(parent, child);
    return (child);
}
