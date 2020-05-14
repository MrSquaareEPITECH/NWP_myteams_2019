/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** user_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_LIST_XML_H

#include <libxml/tree.h>

#include "user_list.h"
#include "xml/xml.h"

user_list_t *user_list_xml_import(xml_element_t *element);
user_list_t *user_list_xml_libxml2_import(xmlNodePtr node);
char *user_list_xml_export(const user_list_t *user_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_USER_USER_LIST_XML_H
