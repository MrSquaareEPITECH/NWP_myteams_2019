/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_list_xml.c
*/

#define _GNU_SOURCE

#include "user_list_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "def/code.h"
#include "user_xml.h"
#include "xml/xml.h"

user_list_t *user_list_xml_import(xml_element_t *element)
{
    user_list_t *list = user_list_create();
    char *content = element->content;
    xml_element_t *user_element = NULL;

    for (user_element = xml_element_create(element->content);
         user_element->name;) {
        user_t *user = user_xml_import(user_element);

        list->push(list, user);

        content = &content[user_element->bounds[1]];
        xml_element_delete(user_element);
        user_element = xml_element_create(content);
    }

    xml_element_delete(user_element);

    return (list);
}

user_list_t *user_list_xml_libxml2_import(xmlNodePtr node)
{
    user_list_t *list = user_list_create();

    for (xmlNodePtr children = node->children; children;
         children = children->next) {
        if (xmlStrcmp(children->name, "user") == 0) {
            user_t *user = user_xml_libxml2_import(children);

            list->push(list, user);
        }
    }

    return (list);
}

char *user_list_xml_export(const user_list_t *user_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<users>\n") == CODE_INVALID)
        return (NULL);

    for (user_node_t *node = user_list->begin; node; node = node->next) {
        char *tmp = xml;
        char *user_xml = user_xml_export(node->user);

        if (asprintf(&xml, "%s%s\n", xml, user_xml) == CODE_INVALID)
            return (NULL);

        free(user_xml);
        free(tmp);
    }

    char *tmp = xml;

    if (asprintf(&xml, "%s</users>", xml) == CODE_INVALID)
        return (NULL);

    free(tmp);

    return (xml);
}
