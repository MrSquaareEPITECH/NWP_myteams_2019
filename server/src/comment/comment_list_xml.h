/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** comment_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_LIST_XML_H

#include "comment_list.h"

comment_list_t *comment_list_xml_import(const char *xml);
char *comment_list_xml_export(const comment_list_t *comment_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_COMMENT_COMMENT_LIST_XML_H
