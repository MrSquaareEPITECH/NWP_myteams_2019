/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_XML_H

#include <libxml/tree.h>

#include "comment.h"

comment_t *comment_xml_import(xmlNodePtr node);
xmlNodePtr comment_xml_export(const comment_t *comment, xmlNodePtr parent);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_XML_H
