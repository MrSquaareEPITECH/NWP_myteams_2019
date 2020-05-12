/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_xml.c
*/

#define _GNU_SOURCE

#include "user_xml.h"

#include <stdio.h>

#include "def/code.h"
#include "private/private_list_xml.h"

user_t *user_xml_import(const char *xml)
{
    (void)(xml);

    return (NULL);
}

char *user_xml_export(const user_t *user)
{
    char *xml = NULL;

    if (asprintf(&xml,
            "<user id=\"%s\" name=\"%s\">\n"
            "%s\n"
            "</user>",
            user->uuid, user->name,
            private_list_xml_export(user->privates)) == CODE_INVALID)
        return (NULL);

    return (xml);
}
