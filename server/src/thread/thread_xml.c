/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_xml.c
*/

#define _GNU_SOURCE

#include "thread_xml.h"

#include <stdio.h>
#include <stdlib.h>

#include "comment/comment_list_xml.h"
#include "def/code.h"

thread_t *thread_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *thread_xml_export(const thread_t *thread)
{
    char *xml = NULL;
    char *comments_xml = comment_list_xml_export(thread->comments);

    if (asprintf(&xml,
            "<thread id=\"%s\" timestamp=\"%ld\" name=\"%s\" "
            "description=\"%s\">\n%s\n</thread>",
            thread->uuid, thread->timestamp, thread->name, thread->description,
            comments_xml) == CODE_INVALID)
        return (NULL);

    free(comments_xml);

    return (xml);
}