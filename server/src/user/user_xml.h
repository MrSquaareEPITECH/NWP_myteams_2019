/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_XML_H

#include <libxml/tree.h>

#include "user.h"
#include "xml/xml.h"

user_t *user_xml_import(xml_element_t *element);
user_t *user_xml_libxml2_import(xmlNodePtr node);
char *user_xml_export(const user_t *user);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_XML_H
