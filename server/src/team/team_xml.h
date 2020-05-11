/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_XML_H

#include "team.h"

team_t *team_xml_import(const char *xml);
char *team_xml_export(const team_t *team);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_XML_H
