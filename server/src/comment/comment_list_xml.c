/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment_list_xml.c
*/

#define _GNU_SOURCE

#include "comment_list_xml.h"

#include <stdio.h>

#include "comment_xml.h"
#include "def/code.h"

comment_list_t *comment_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *comment_list_xml_export(const comment_list_t *comment_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<comments>\n") == CODE_INVALID)
        return (NULL);

    for (comment_node_t *node = comment_list->begin; node; node = node->next)
        if (asprintf(&xml,
                "%s"
                "%s\n",
                xml, comment_xml_export(node->comment)) == CODE_INVALID)
            return (NULL);

    if (asprintf(&xml,
            "%s"
            "</comments>",
            xml) == CODE_INVALID)
        return (NULL);

    return (xml);
}
