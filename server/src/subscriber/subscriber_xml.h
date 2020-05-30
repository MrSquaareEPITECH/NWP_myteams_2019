/*
** EPITECH PROJECT, 2020
** server
** File description:
** subscriber_xml.h
*/

#ifndef SERVER_SRC_SUBSCRIBER_SUBSCRIBER_XML_H
#define SERVER_SRC_SUBSCRIBER_SUBSCRIBER_XML_H

#include "subscriber.h"
#include "xml/xml_element.h"

subscriber_t *subscriber_xml_import(xml_element_t *element);
char *subscriber_xml_export(subscriber_t *subscriber);

#endif // SERVER_SRC_SUBSCRIBER_SUBSCRIBER_XML_H
