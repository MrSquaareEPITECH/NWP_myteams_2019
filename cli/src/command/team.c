/*
** EPITECH PROJECT, 2020
** cli
** File description:
** team
*/

#include "my.h"

int team_check(char **tab)
{
    char *word = take_word(tab[0], 7);

    if (strncasecmp(word, "CREATE", 6) == 0)
        //appel fonction loggin_client.h create
    if (strncasecmp(word, "EXISTS", 6) == 0)
        //appel fonction loggin_client.h exits
    if (strncasecmp(word, "INFO", 4) == 0)
        //appel fonction loggin_client.h info
    if (strncasecmp(word, "LIST", 4) == 0)
        //appel fonction loggin_client.h list
    if (strncasecmp(word, "SUBSCRIBERS", 11) == 0)
        //appel fonction loggin_client.h subscribers
    return (0);
}