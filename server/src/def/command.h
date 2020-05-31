/*
** EPITECH PROJECT, 2020
** server
** File description:
** command.h
*/

#ifndef SERVER_SRC_DEF_COMMAND_H
#define SERVER_SRC_DEF_COMMAND_H

#include <stddef.h>

#include "client/client.h"
#include "command/create.h"
#include "command/help.h"
#include "command/info.h"
#include "command/list.h"
#include "command/login.h"
#include "command/logout.h"
#include "command/messages.h"
#include "command/send.h"
#include "command/subscribe.h"
#include "command/subscribed.h"
#include "command/unsubscribe.h"
#include "command/use.h"
#include "command/user.h"
#include "command/users.h"
#include "server/server.h"

typedef struct command_s command_t;

struct command_s {
    const char *name;
    const char *help;
    int (*func)(server_t *server, client_t *client, int argc, char **argv);
};

static const command_t COMMANDS[] = {
    {"/create", NULL, create_command},
    {"/help", NULL, help_command},
    {"/info", NULL, info_command},
    {"/list", NULL, list_command},
    {"/login", NULL, login_command},
    {"/logout", NULL, logout_command},
    {"/messages", NULL, messages_command},
    {"/send", NULL, send_command},
    {"/subscribe", NULL, subscribe_command},
    {"/subscribed", NULL, subscribed_command},
    {"/unsubscribe", NULL, unsubscribe_command},
    {"/use", NULL, use_command},
    {"/user", NULL, user_command},
    {"/users", NULL, users_command},
    {NULL, NULL, NULL},
};

#endif // SERVER_SRC_DEF_COMMAND_H
