/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_H

typedef struct xml_attribute_s xml_attribute_t;
typedef struct xml_element_s xml_element_t;

struct xml_attribute_s {
    char *name;
    char *value;
};

struct xml_element_s {
    char *name;
    xml_attribute_t **attributes;
    char *content;
    long bounds[2];
};

xml_element_t *xml_element_create(const char *xml);
void xml_element_delete(xml_element_t *element);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_H
