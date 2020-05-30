/*
** EPITECH PROJECT, 2020
** server
** File description:
** user_xml.h
*/

#ifndef SERVER_SRC_USER_USER_XML_H
#define SERVER_SRC_USER_USER_XML_H

#include "user.h"
#include "xml/xml_element.h"

user_t *user_xml_import(xml_element_t *element);
char *user_xml_export(user_t *user);

#endif // SERVER_SRC_USER_USER_XML_H
