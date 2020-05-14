/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_list_xml.c
*/

#define _GNU_SOURCE

#include "thread_list_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "def/code.h"
#include "thread_xml.h"

thread_list_t *thread_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *thread_list_xml_export(const thread_list_t *thread_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<threads>\n") == CODE_INVALID)
        return (NULL);

    for (thread_node_t *node = thread_list->begin; node; node = node->next) {
        char *tmp = xml;
        char *thread_xml = thread_xml_export(node->thread);

        if (asprintf(&xml, "%s%s\n", xml, thread_xml) == CODE_INVALID)
            return (NULL);

        free(thread_xml);
        free(tmp);
    }

    char *tmp = xml;

    if (asprintf(&xml, "%s</threads>", xml) == CODE_INVALID)
        return (NULL);

    free(tmp);

    return (xml);
}
