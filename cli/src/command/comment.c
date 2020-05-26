/*
** EPITECH PROJECT, 2020
** cli
** File description:
** comment
*/

#include "my.h"

int comment_check(char **tab)
{
    char *word = take_word(tab[0], 7);

    if (strncasecmp(word, "SEND", 4) == 0)
        //appel fonction loggin_client.h send
    if (strncasecmp(word, "LIST", 4) == 0)
        //appel fonction loggin_client.h list
    return (0);
}