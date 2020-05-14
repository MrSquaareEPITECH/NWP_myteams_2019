/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_list_xml.c
*/

#define _GNU_SOURCE

#include "team_list_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "def/code.h"
#include "team_xml.h"

team_list_t *team_list_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *team_list_xml_export(const team_list_t *team_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<teams>\n") == CODE_INVALID)
        return (NULL);

    for (team_node_t *node = team_list->begin; node; node = node->next) {
        char *tmp = xml;
        char *team_xml = team_xml_export(node->team);

        if (asprintf(&xml, "%s%s\n", xml, team_xml) == CODE_INVALID)
            return (NULL);

        free(team_xml);
        free(tmp);
    }

    char *tmp = xml;

    if (asprintf(&xml, "%s</teams>", xml) == CODE_INVALID)
        return (NULL);

    free(tmp);

    return (xml);
}
