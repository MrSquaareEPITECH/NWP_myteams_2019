/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_LIST_XML_H

#include "channel_list.h"

channel_list_t *channel_list_xml_import(const char *xml);
char *channel_list_xml_export(const channel_list_t *channel_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_LIST_XML_H
