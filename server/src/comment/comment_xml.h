/*
** EPITECH PROJECT, 2020
** server
** File description:
** comment_xml.h
*/

#ifndef SERVER_SRC_COMMENT_COMMENT_XML_H
#define SERVER_SRC_COMMENT_COMMENT_XML_H

#include "comment.h"
#include "xml/xml_element.h"

comment_t *comment_xml_import(thread_t *parent, xml_element_t *element);
char *comment_xml_export(comment_t *comment);

#endif // SERVER_SRC_COMMENT_COMMENT_XML_H
