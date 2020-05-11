/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** team_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_LIST_XML_H

#include "team_list.h"

team_list_t *team_list_xml_import(const char *xml);
char *team_list_xml_export(const team_list_t *team_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_TEAM_TEAM_LIST_XML_H
