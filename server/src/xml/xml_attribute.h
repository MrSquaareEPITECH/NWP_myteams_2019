/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml_attribute.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_ATTRIBUTE_H
#define NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_ATTRIBUTE_H

#include "list/list.h"

typedef struct xml_attribute_s xml_attribute_t;
typedef struct xml_element_s xml_element_t;

struct xml_attribute_s {
    char *name;
    char *value;
};

char *xml_attributes_get(list_t *attributes, const char *name);
list_t *xml_attributes_parse(const char *xml);
xml_attribute_t *xml_attribute_create(char *name, char *value);
void xml_attribute_delete(xml_attribute_t *attribute);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_ATTRIBUTE_H
