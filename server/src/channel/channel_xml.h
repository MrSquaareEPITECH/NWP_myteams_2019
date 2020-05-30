/*
** EPITECH PROJECT, 2020
** server
** File description:
** channel_xml.h
*/

#ifndef SERVER_SRC_CHANNEL_CHANNEL_XML_H
#define SERVER_SRC_CHANNEL_CHANNEL_XML_H

#include "channel.h"
#include "xml/xml_element.h"

channel_t *channel_xml_import(team_t *parent, xml_element_t *element);
char *channel_xml_export(channel_t *channel);

#endif // SERVER_SRC_CHANNEL_CHANNEL_XML_H
