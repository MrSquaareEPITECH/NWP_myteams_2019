/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_H

typedef struct xml_tag_s xml_tag_t;
typedef struct xml_property_s xml_property_t;

struct xml_property_s {
    char *name;
    char *value;
};

struct xml_tag_s {
    xml_property_t *properties;
    char *content;
};

xml_tag_t *xml_create(const char *xml, const char *tag);
void xml_delete(xml_tag_t *xml_tag);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_H
