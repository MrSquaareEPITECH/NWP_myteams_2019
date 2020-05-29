/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include "pcre/pcre.h"
#include "xml/xml.h"

#include <string.h>

int main(void)
{
    char *doc = "<team uuid=\"10-25211-12255-1522\" name=\"Salut à tous\">\n    <user id=\"tttttttt\">Hahahaha</user>\n    <user id=\"tttttttt\">Hehehehe</user>\n</team>";
    char *format = xml_format(doc);
    xml_element_t *element = xml_element_create(format);

    return (0);
}
