/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdlib.h>

#include "xml/xml_attribute.h"
#include "xml/xml_element.h"
#include "xml/xml_file.h"

int main(void)
{
    char *xml = xml_from_file("teams.xml");
    xml_element_t *element = xml_element_parse(xml);
    xml_element_t *team = xml_element_get(element->children, "team");
    char *id = xml_attributes_get(team->attributes, "id");

    xml_element_delete(element);
    free(xml);
    return (0);
}
