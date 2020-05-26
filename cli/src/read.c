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
        handle_login(cli);
    if (strncasecmp(cli->buffer, "/logout", 7) == 0)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    if (strncasecmp(cli->buffer, "/users", 6) == 0)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    if (strncasecmp(cli->buffer, "/user", 5) == 0)
        handle_user(cli);
    if (strncasecmp(cli->buffer, "/use", 4) == 0)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    else
        display_help();
}

void check_command(client_t *cli)
{
    if (strncasecmp(cli->buffer, "/help", 5) == 0)
        display_help();
    if (strncasecmp(cli->buffer, "/create", 7) == 0)
        handle_create(cli);
    if (strncasecmp(cli->buffer, "/information", 12) == 0)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    if (strncasecmp(cli->buffer, "/list", 5) == 0)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    if (strncasecmp(cli->buffer, "/send", 5) == 0)
        handle_send(cli);
    if (strncasecmp(cli->buffer, "/subscribed", 12) == 0)
        send(cli->port, cli->buffer, SIZE_OF_BUFFER, 0);
    if (strncasecmp(cli->buffer, "/unsubscribe", 12) == 0)
        handle_subscribe(cli, 0);
    if (strncasecmp(cli->buffer, "/subscribe", 10) == 0)
        handle_subscribe(cli, 1);
    else
        handle_client(cli);
}