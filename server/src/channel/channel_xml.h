/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** channel_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_XML_H

#include "channel.h"

channel_t *channel_xml_import(const char *xml);
char *channel_xml_export(const channel_t *channel);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_CHANNEL_CHANNEL_XML_H