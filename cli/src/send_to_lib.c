/*
** EPITECH PROJECT, 2020
** cli
** File description:
** send_to_lib
*/

#include "my.h"

void check_responses(char **tab)
{
    char *word = take_word(tab[0], 0);

    if (strncasecmp(word, "CHANNEL", 7) == 0)
        channel_check(tab);
    if (strncasecmp(word, "COMMENT", 7) == 0)
        comment_check(tab);
    if (strncasecmp(word, "MESSAGE", 7) == 0)
        message_check(tab);
    if (strncasecmp(word, "TEAM", 4) == 0)
        team_check(tab);
    if (strncasecmp(word, "THREAD", 6) == 0)
        thread_check(tab);
    if (strncasecmp(word, "USER", 4) == 0)
        user_check(tab);
    else
//        error
}

void parse_msg(client_t *cli, char *str)
{
    char **tab = NULL;
    int lines = count_lines(str);

    tab = str_split(str, '\n');
    if (lines == 1)
        check_event(tab);
    else
        check_responses(tab);
}