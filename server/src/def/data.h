/*
** EPITECH PROJECT, 2020
** server
** File description:
** data.h
*/

#ifndef SERVER_SRC_DEF_DATA_H
#define SERVER_SRC_DEF_DATA_H

typedef const char* const c_string;

#define g_string static c_string

g_string DATA_CHANNEL = "\"%s\" \"%s\" \"%s\"\n";
g_string DATA_COMMENT = "\"%ld\" \"%s\"\n";
g_string DATA_TEAM = "\"%s\" \"%s\" \"%s\"\n";
g_string DATA_THREAD = "\"%s\" \"%ld\" \"%s\" \"%s\"\n";
g_string DATA_USER = "\"%s\" \"%s\"\n";

#endif // SERVER_SRC_DEF_DATA_H
