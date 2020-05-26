/*
** EPITECH PROJECT, 2020
** cli
** File description:
** user
*/

#include "my.h"

int user_check(char **tab)
{
    char *word = take_word(tab[0], 7);

    if (strncasecmp(word, "LOGIN", 5) == 0)
        //appel fonction loggin_client.h login
    if (strncasecmp(word, "EXISTS", 6) == 0)
        //appel fonction loggin_client.h exits
    if (strncasecmp(word, "INFO", 4) == 0)
        //appel fonction loggin_client.h info
    if (strncasecmp(word, "LIST", 4) == 0)
        //appel fonction loggin_client.h list
    if (strncasecmp(word, "LOGOUT", 6) == 0)
        //appel fonction loggin_client.h logout
    if (strncasecmp(word, "SUBSCRIBE", 9) == 0)
        //appel fonction loggin_client.h subscribe
    if (strncasecmp(word, "SUBSCRIBTION", 12) == 0)
        //appel fonction loggin_client.h subscribtion
    if (strncasecmp(word, "UNSUBSCRIBE", 11) == 0)
        //appel fonction loggin_client.h unsubscribe
    return (0);
}