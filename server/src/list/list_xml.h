/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_XML_H

#include <libxml/tree.h>

#include "list.h"

typedef void *(*import_t)(xmlNodePtr node);
typedef xmlNodePtr (*export_t)(void *obj, xmlNodePtr parent);

#define import_c(func_ptr) ((import_t)(func_ptr))
#define export_c(func_ptr) ((export_t)(func_ptr))

list_t *list_xml_import(xmlNodePtr node, const char *name, import_t import);
xmlNodePtr list_xml_export(const list_t *list, xmlNodePtr parent, export_t export);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_XML_H
