/*
** EPITECH PROJECT, 2020
** server
** File description:
** xml.h
*/

#ifndef SERVER_SRC_XML_XML_H
#define SERVER_SRC_XML_XML_H

#include "list/list.h"

typedef struct xml_attribute_s xml_attribute_t;
typedef struct xml_element_s xml_element_t;

struct xml_attribute_s {
    char *name;
    char *value;
};

struct xml_element_s {
    char *name;
    char *content;
    list_t *attributes;
    list_t *children;
    long bounds[2];
};

char *xml_format(const char *xml);
list_t *xml_attributes_create(const char *xml);
void xml_attribute_delete(xml_attribute_t *attribute);
xml_element_t *xml_element_create(const char *xml);
void xml_element_delete(xml_element_t *element);

#endif // SERVER_SRC_XML_XML_H
