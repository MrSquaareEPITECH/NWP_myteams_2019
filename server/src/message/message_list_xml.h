/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_LIST_XML_H

#include "message_list.h"
#include "xml/xml.h"

message_list_t *message_list_xml_import(xml_element_t *element);
char *message_list_xml_export(const message_list_t *message_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_LIST_XML_H
