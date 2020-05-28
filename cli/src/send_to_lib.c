/*
** EPITECH PROJECT, 2020
** cli
** File description:
** send_to_lib
*/

#include "my.h"

void check_responses(char **tab)
{
    char *status = check_status(tab[2]);

    if (strncasecmp(tab[0], "GLOBAL", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[0], "CHANNEL", 7) == 0)
        channel_check(tab, status);
    if (strncasecmp(tab[0], "COMMENT", 7) == 0)
        comment_check(tab, status);
    if (strncasecmp(tab[0], "MESSAGE", 7) == 0)
        message_check(tab, status);
    if (strncasecmp(tab[0], "TEAM", 4) == 0)
        team_check(tab, status);
    if (strncasecmp(tab[0], "THREAD", 6) == 0)
        thread_check(tab, status);
    if (strncasecmp(tab[0], "USER", 4) == 0)
        user_check(tab, status);
}

void handle_event(char **tab)
{
    if (strcasecmp(tab[0], "CHANNEL") == 0)
        client_event_channel_created(tab[2], tab[3], tab[4]);
    if (strcasecmp(tab[0], "COMMENT") == 0)
        client_event_thread_message_received(tab[2], tab[3], tab[4], tab[5]);
    if (strcasecmp(tab[0], "MESSAGE") == 0)
        client_event_private_message_received(tab[2], tab[3]);
    if (strcasecmp(tab[0], "TEAM") == 0)
        client_event_team_created(tab[2], tab[3], tab[4]);
    if (strcasecmp(tab[0], "THREAD") == 0)
        client_event_thread_created(tab[2], tab[3], atoi(tab[4]), tab[5], tab[6]);
    if (strcasecmp(tab[0], "USER") == 0) {
        if (strcasecmp(tab[1], "LOGGEDIN") == 0)
            client_event_loggedin(tab[2], tab[3]);
        else if (strcasecmp(tab[1], "LOGGEDOUT") == 0)
            client_event_loggedout(tab[2], tab[3]);
    }
}

void parse_msg(char *str)
{
    char **tab = NULL;

    str = replace_char_array(str, '\n');
    tab = str_split(str, ' ');
    tab = replace_char_double_array(tab, ' ');
    if (strcasecmp(tab[3], "OK") == 0 || strcasecmp(tab[3], "KO") == 0)
        check_responses(tab);
    else
        handle_event(tab);
}