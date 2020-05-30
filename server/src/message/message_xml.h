/*
** EPITECH PROJECT, 2020
** server
** File description:
** message_xml.h
*/

#ifndef SERVER_SRC_MESSAGE_MESSAGE_XML_H
#define SERVER_SRC_MESSAGE_MESSAGE_XML_H

#include "message.h"
#include "xml/xml_element.h"

message_t *message_xml_import(xml_element_t *element);
char *message_xml_export(message_t *message);

#endif // SERVER_SRC_MESSAGE_MESSAGE_XML_H
