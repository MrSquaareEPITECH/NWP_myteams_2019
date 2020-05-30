/*
** EPITECH PROJECT, 2020
** server
** File description:
** private_xml.h
*/

#ifndef SERVER_SRC_PRIVATE_PRIVATE_XML_H
#define SERVER_SRC_PRIVATE_PRIVATE_XML_H

#include "private.h"
#include "xml/xml_element.h"

private_t *private_xml_import(xml_element_t *element);
char *private_xml_export(private_t *priv);

#endif // SERVER_SRC_PRIVATE_PRIVATE_XML_H
