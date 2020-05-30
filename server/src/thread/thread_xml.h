/*
** EPITECH PROJECT, 2020
** server
** File description:
** thread_xml.h
*/

#ifndef SERVER_SRC_THREAD_THREAD_XML_H
#define SERVER_SRC_THREAD_THREAD_XML_H

#include "thread.h"
#include "xml/xml_element.h"

thread_t *thread_xml_import(channel_t *parent, xml_element_t *element);
char *thread_xml_export(thread_t *thread);

#endif // SERVER_SRC_THREAD_THREAD_XML_H
