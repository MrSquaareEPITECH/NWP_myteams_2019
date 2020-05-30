/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_xml.c
*/

#include "list_xml.h"

#include <stdlib.h>

#include "util/string.h"

list_t *list_xml_import(xml_element_t *element, import_t import)
{
    list_t *list = list_create();

    for (node_t *node = element->children->begin; node; node = node->next) {
        xml_element_t *child = (xml_element_t *)(node->obj);
        void *obj = import(child);

        list_push(list, obj);
    }
    return (list);
}

list_t *list_xml_import_p(
    xml_element_t *element, import_p_t import, void *parent)
{
    list_t *list = list_create();

    for (node_t *node = element->children->begin; node; node = node->next) {
        xml_element_t *child = (xml_element_t *)(node->obj);
        void *obj = import(parent, child);

        list_push(list, obj);
    }
    return (list);
}

char *list_xml_export(
    list_t *list, const char *offset, const char *tag, export_t export)
{
    char *xml = strfmt("%s<%s>\n", offset, tag);
    char *tmp = NULL;

    for (node_t *node = list->begin; node; node = node->next) {
        char *obj_xml = export(node->obj);

        tmp = xml;
        xml = strfmt("%s%s\n", xml, obj_xml);
        free(tmp);
    }
    tmp = xml;
    xml = strfmt("%s%s</%s>", xml, offset, tag);
    free(tmp);
    return (xml);
}
