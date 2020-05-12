/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_list_xml.c
*/

#define _GNU_SOURCE

#include "private_list_xml.h"

#include <stdio.h>

#include "def/code.h"
#include "private_xml.h"

private_list_t *private_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *private_list_xml_export(const private_list_t *private_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<privates>\n") == CODE_INVALID)
        return (NULL);

    for (private_node_t *node = private_list->begin; node; node = node->next)
        if (asprintf(&xml,
                "%s"
                "%s\n",
                xml, private_xml_export(node->private)) == CODE_INVALID)
            return (NULL);

    if (asprintf(&xml,
            "%s"
            "</privates>",
            xml) == CODE_INVALID)
        return (NULL);

    return (xml);
}
