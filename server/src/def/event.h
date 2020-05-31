/*
** EPITECH PROJECT, 2020
** server
** File description:
** event.h
*/

#ifndef SERVER_SRC_DEF_EVENT_H
#define SERVER_SRC_DEF_EVENT_H

typedef const char* const c_string;

#define g_string static c_string

g_string EVENT_CHANNEL_CREATED = "CHANNEL CREATED\n";
g_string EVENT_COMMENT_CREATED = "COMMENT CREATED\n";
g_string EVENT_MESSAGE_CREATED = "MESSAGE CREATED\n";
g_string EVENT_TEAM_CREATED = "TEAM CREATED\n";
g_string EVENT_THREAD_CREATED = "THREAD CREATED\n";
g_string EVENT_USER_LOGGEDIN = "USER LOGGEDIN\n";
g_string EVENT_USER_LOGGEDOUT = "USER LOGGEDOUT\n";

#endif // SERVER_SRC_DEF_EVENT_H
