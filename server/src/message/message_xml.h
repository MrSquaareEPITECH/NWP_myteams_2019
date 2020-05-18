/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_XML_H

#include <libxml/tree.h>

#include "message.h"

message_t *message_xml_import(xmlNodePtr node);
xmlNodePtr message_xml_export(const message_t *message, xmlNodePtr parent);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_XML_H
