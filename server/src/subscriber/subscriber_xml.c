/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber_xml.c
*/

#define _GNU_SOURCE

#include "subscriber_xml.h"

#include <stdio.h>

#include "def/code.h"

subscriber_t *subscriber_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *subscriber_xml_export(const subscriber_t *subscriber)
{
    char *xml = NULL;

    if (asprintf(&xml, "\"%s\"", subscriber->uuid) == CODE_INVALID)
        return (NULL);

    return (xml);
}
