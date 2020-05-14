/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_list_xml.c
*/

#define _GNU_SOURCE

#include "private_list_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "def/code.h"
#include "private_xml.h"

private_list_t *private_list_xml_import(xml_element_t *element)
{
    private_list_t *list = private_list_create();
    char *content = element->content;
    xml_element_t *private_element = NULL;

    for (private_element = xml_element_create(element->content);
         private_element->name;) {
        private_t *private = private_xml_import(private_element);

        list->push(list, private);

        content = &content[private_element->bounds[1]];
        xml_element_delete(private_element);
        private_element = xml_element_create(content);
    }

    xml_element_delete(private_element);

    return (list);
}

char *private_list_xml_export(const private_list_t *private_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<privates>\n") == CODE_INVALID)
        return (NULL);

    for (private_node_t *node = private_list->begin; node; node = node->next) {
        char *tmp = xml;
        char *private_xml = private_xml_export(node->private);

        if (asprintf(&xml, "%s%s\n", xml, private_xml) == CODE_INVALID)
            return (NULL);

        free(private_xml);
        free(tmp);
    }

    char *tmp = xml;

    if (asprintf(&xml, "%s</privates>", xml) == CODE_INVALID)
        return (NULL);

    free(tmp);

    return (xml);
}
