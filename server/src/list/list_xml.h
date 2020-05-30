/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_xml.h
*/

#ifndef SERVER_SRC_LIST_LIST_XML_H
#define SERVER_SRC_LIST_LIST_XML_H

#include "list.h"
#include "xml/xml_element.h"

typedef void *(*import_t)(xml_element_t *element);
typedef void *(*import_p_t)(void *parent, xml_element_t *element);
typedef char *(*export_t)(void *obj);

list_t *list_xml_import(xml_element_t *element, import_t import);
list_t *list_xml_import_p(
    xml_element_t *element, import_p_t import, void *parent);
char *list_xml_export(
    list_t *list, const char *offset, const char *tag, export_t export);

#endif // SERVER_SRC_LIST_LIST_XML_H
