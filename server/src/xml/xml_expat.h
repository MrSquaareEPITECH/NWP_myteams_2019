/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_EXPAT_H
#define NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_EXPAT_H

#ifdef XML_LARGE_SIZE
#define XML_FMT_INT_MOD "ll"
#else
#define XML_FMT_INT_MOD "l"
#endif

#ifdef XML_UNICODE_WCHAR_T
#include <wchar.h>
#define XML_FMT_STR "ls"
#else
#define XML_FMT_STR "s"
#endif

void xml_expat_print(const char *xml);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_XML_XML_EXPAT_H
