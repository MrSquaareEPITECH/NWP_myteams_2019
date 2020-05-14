/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_XML_H

#include "thread.h"

thread_t *thread_xml_import(const char *xml);
char *thread_xml_export(const thread_t *thread);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_XML_H