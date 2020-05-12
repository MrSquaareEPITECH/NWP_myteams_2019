/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_LIST_XML_H

#include "subscriber_list.h"

subscriber_list_t *subscriber_list_xml_import(const char *xml);
char *subscriber_list_xml_export(const subscriber_list_t *subscriber_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_LIST_XML_H
