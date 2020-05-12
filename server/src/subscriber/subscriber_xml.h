/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** subscriber_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_XML_H

#include "subscriber.h"

subscriber_t *subscriber_xml_import(const char *xml);
char *subscriber_xml_export(const subscriber_t *subscriber);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_SUBSCRIBER_SUBSCRIBER_XML_H
