/*
** EPITECH PROJECT, 2020
** server
** File description:
** team_xml.h
*/

#ifndef SERVER_SRC_TEAM_TEAM_XML_H
#define SERVER_SRC_TEAM_TEAM_XML_H

#include "team.h"
#include "xml/xml_element.h"

team_t *team_xml_import(xml_element_t *element);
char *team_xml_export(team_t *team);

#endif // SERVER_SRC_TEAM_TEAM_XML_H
