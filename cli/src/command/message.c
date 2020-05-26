/*
** EPITECH PROJECT, 2020
** cli
** File description:
** message
*/

#include "my.h"

int message_check(char **tab)
{
    char *word = take_word(tab[0], 7);

    if (strncasecmp(word, "EXISTS", 6) == 0)
        //appel fonction loggin_client.h exits
    if (strncasecmp(word, "SEND", 4) == 0)
        //appel fonction loggin_client.h send
    if (strncasecmp(word, "LIST", 4) == 0)
        //appel fonction loggin_client.h list
    return (0);
}