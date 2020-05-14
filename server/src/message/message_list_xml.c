/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_list_xml.c
*/

#define _GNU_SOURCE

#include "message_list_xml.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def/code.h"
#include "message_xml.h"
#include "pcre/pcre.h"
#include "util/string.h"

message_list_t *message_list_xml_import(xml_element_t *element)
{
    message_list_t *list = message_list_create();
    char **messages = strsplit(element->content, "\n");

    for (int i = 0; messages[i]; ++i) {
        message_t *message = malloc(sizeof(message_t));

        memset(message->body, 0, sizeof(message->body));

        int *matches = pcre_match(
            messages[i], (int)(strlen(messages[i])), "\"(\\d+)\" \"(.*)\"", 2);

        if (matches[3] <= matches[2] || matches[5] <= matches[4])
            continue;

        char *timestamp = strndup(&(messages[i][matches[2]]), matches[3] - matches[2]);

        message->timestamp = strtol(timestamp, NULL, 10);

        char *body = strndup(&(messages[i][matches[4]]), matches[5] - matches[4]);

        strncpy(message->body, body, MAX_BODY_LENGTH);

        free(body);
        free(timestamp);
        free(matches);
        free(messages[i]);

        list->push(list, message);
    }

    free(messages);

    return (list);
}

char *message_list_xml_export(const message_list_t *message_list)
{
    char *xml = NULL;

    if (asprintf(&xml, "<messages>\n") == CODE_INVALID)
        return (NULL);

    for (message_node_t *node = message_list->begin; node; node = node->next) {
        char *tmp = xml;
        char *message_xml = message_xml_export(node->message);

        if (asprintf(&xml, "%s%s\n", xml, message_xml) == CODE_INVALID)
            return (NULL);

        free(message_xml);
        free(tmp);
    }

    char *tmp = xml;

    if (asprintf(&xml, "%s</messages>", xml) == CODE_INVALID)
        return (NULL);

    free(tmp);

    return (xml);
}
