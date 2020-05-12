/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_list_xml.c
*/

#define _GNU_SOURCE

#include "user_list_xml.h"

#include <stdio.h>

#include "def/code.h"
#include "user_xml.h"

user_list_t *user_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *user_list_xml_export(const user_list_t *user_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<users>\n") == CODE_INVALID)
        return (NULL);

    for (user_node_t *node = user_list->begin; node; node = node->next)
        if (asprintf(&xml,
                "%s"
                "%s\n",
                xml, user_xml_export(node->user)) == CODE_INVALID)
            return (NULL);

    if (asprintf(&xml,
            "%s"
            "</users>",
            xml) == CODE_INVALID)
        return (NULL);

    return (xml);
}
