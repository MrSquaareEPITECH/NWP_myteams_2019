/*
** EPITECH PROJECT, 2020
** server
** File description:
** xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_UTIL_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_UTIL_XML_H

#include <libxml/tree.h>

xmlNodePtr xml_get_child(xmlNodePtr parent, const xmlChar *name);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_UTIL_XML_H
