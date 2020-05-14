/*
** EPITECH PROJECT, 2020
** server
** File description:
** list_xml.h
*/

#ifndef SERVER_SRC_LIST_LIST_XML_H
#define SERVER_SRC_LIST_LIST_XML_H

#include "list.h"

typedef void *(*import_t)(void *obj);
typedef char *(*export_t)(void *obj);

#define import(func_ptr) ((import_t)(func_ptr))
#define export(func_ptr) ((export_t)(func_ptr))

list_t *list_xml_import(const char *xml, import_t imp);
char *list_xml_export(const list_t *list, const char *tag, export_t exp);

#endif // SERVER_SRC_LIST_LIST_XML_H
