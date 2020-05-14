/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_LIST_XML_H

#include "private_list.h"
#include "xml/xml.h"

private_list_t *private_list_xml_import(xml_element_t *element);
char *private_list_xml_export(const private_list_t *private_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_LIST_XML_H
