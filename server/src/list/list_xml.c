/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_xml.c
*/

#include "list_xml.h"

list_t *list_xml_import(xmlNodePtr node, const char *name, import_t import)
{
    list_t *list = list_create();

    for (xmlNodePtr child = node->children; child; child = child->next) {
        if (xmlStrcmp(child->name, BAD_CAST name) == 0) {
            void *obj = import(child);

            list_push(list, obj);
        }
    }
    return (list);
}

xmlNodePtr list_xml_export(
    const list_t *list, xmlNodePtr parent, export_t export)
{
    for (node_t *node = list->begin; node; node = node->next) {
        xmlNodePtr child = export(node->obj, parent);
        xmlAddChild(parent, child);
    }
    return (parent);
}
