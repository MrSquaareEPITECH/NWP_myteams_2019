/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** thread_list_xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_LIST_XML_H
#define NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_LIST_XML_H

#include "thread_list.h"

thread_list_t *thread_list_xml_import(const char *xml);
char *thread_list_xml_export(const thread_list_t *thread_list);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_THREAD_THREAD_LIST_XML_H
