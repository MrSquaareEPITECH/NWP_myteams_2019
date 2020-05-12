/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** private_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_XML_H

#include "private.h"

private_t *private_xml_import(const char *xml);
char *private_xml_export(const private_t *private);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_PRIVATE_PRIVATE_XML_H
