/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_XML_H

#include <libxml/tree.h>

#include "private.h"

private_t *private_xml_import(xmlNodePtr node);
xmlNodePtr private_xml_export(const private_t *private, xmlNodePtr parent);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_XML_H
