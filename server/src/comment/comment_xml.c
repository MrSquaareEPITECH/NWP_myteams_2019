/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment_xml.c
*/

#define _GNU_SOURCE

#include "comment_xml.h"

#include <stdio.h>

#include "def/code.h"

comment_t *comment_xml_import(const char *xml)
{
}

char *comment_xml_export(const comment_t *comment)
{
    char *xml = NULL;

    if (asprintf(&xml, "\"%ld\" \"%s\"", comment->timestamp, comment->body) ==
        CODE_INVALID)
        return (NULL);

    return (xml);
}
