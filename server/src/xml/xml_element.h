/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml_element.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_ELEMENT_H
#define NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_ELEMENT_H

#include "list/list.h"

typedef struct xml_element_s xml_element_t;

struct xml_element_s {
    char *name;
    char *content;
    list_t *attributes;
    list_t *children;
    long bounds[2];
};

xml_element_t *xml_element_get(list_t *elements, const char *name);
xml_element_t *xml_element_parse(const char *xml);
xml_element_t *xml_element_create(
    char *name, char *attributes, char *content, const int *bounds);
void xml_element_delete(xml_element_t *element);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_ELEMENT_H
