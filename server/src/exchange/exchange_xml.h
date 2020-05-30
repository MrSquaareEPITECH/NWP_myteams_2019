/*
** EPITECH PROJECT, 2020
** server
** File description:
** exchange_xml.h
*/

#ifndef SERVER_SRC_EXCHANGE_EXCHANGE_XML_H
#define SERVER_SRC_EXCHANGE_EXCHANGE_XML_H

#include "exchange.h"
#include "xml/xml_element.h"

exchange_t *exchange_xml_import(xml_element_t *element);
char *exchange_xml_export(exchange_t *exchange);

#endif // SERVER_SRC_EXCHANGE_EXCHANGE_XML_H
