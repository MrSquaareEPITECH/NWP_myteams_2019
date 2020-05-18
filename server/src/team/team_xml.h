/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_XML_H

#include <libxml/tree.h>

#include "team.h"

team_t *team_xml_import(xmlNodePtr node);
xmlNodePtr team_xml_export(const team_t *team, xmlNodePtr parent);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_XML_H
