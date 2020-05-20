/*
** EPITECH PROJECT, 2020
** src
** File description:
** read
*/

#include "my.h"

char *get_command(void)
{
    char *str = NULL;
    size_t size = 0;

    if (getline(&str, &size, stdin) == -1)
        return (NULL);
    return (str);
}

void handle_client(client_t *cli)
{
    if (strncasecmp(cli->buffer, "/login", 6) == 0)
        handle_login();
    else if (strncasecmp(cli->buffer, "/logout", 7) == 0)
        handle_logout();
    else if (strncasecmp(cli->buffer, "/subscriptions", 14) == 0)
        handle_subscriptions();
}

void check_command(client_t *cli)
{
    if (strncasecmp(cli->buffer, "/help", 5) == 0)
        display_help();
    else if (strncasecmp(cli->buffer, "/create", 7) == 0)
        handle_create();
    else if (strncasecmp(cli->buffer, "/exists", 7) == 0)
        handle_exist();
    else if (strncasecmp(cli->buffer, "/information", 12) == 0)
        handle_information();
    else if (strncasecmp(cli->buffer, "/list", 5) == 0)
        handle_list();
    else if (strncasecmp(cli->buffer, "/send", 5) == 0)
        handle_send();
    else if (strncasecmp(cli->buffer, "/subscribers", 12) == 0)
        handle_subscribers();
    else if (strncasecmp(cli->buffer, "/unsubscribe", 12) == 0)
        handle_unsubscribe();
    else if (strncasecmp(cli->buffer, "/subscribe", 10) == 0)
        handle_subscribe();
    else
        handle_client(cli);
}