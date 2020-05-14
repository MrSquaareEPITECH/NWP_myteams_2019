/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_xml.c
*/

#define _GNU_SOURCE

#include "list_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "def/code.h"

list_t *list_xml_import(const char *xml, import_t imp)
{
    (void)(xml);
    (void)(imp);

    return (NULL);
}

char *list_xml_export(const list_t *list, const char *tag, export_t exp)
{
    char *xml = NULL;

    if (asprintf(&xml, "<%s>\n", tag) == CODE_INVALID)
        return (NULL);

    for (node_t *node = list->begin; node; node = node->next) {
        char *tmp = xml;
        char *obj_xml = exp(node->obj);

        if (asprintf(&xml, "%s%s\n", xml, obj_xml) == CODE_INVALID)
            return (NULL);

        free(obj_xml);
        free(tmp);
    }

    char *tmp = xml;

    if (asprintf(&xml, "%s</%s>", xml, tag) == CODE_INVALID)
        return (NULL);

    free(tmp);

    return (xml);
}
