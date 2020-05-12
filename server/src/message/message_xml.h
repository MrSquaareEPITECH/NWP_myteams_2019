/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** message_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_XML_H

#include "message.h"

message_t *message_xml_import(const char *xml);
char *message_xml_export(const message_t *message);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_MESSAGE_MESSAGE_XML_H
