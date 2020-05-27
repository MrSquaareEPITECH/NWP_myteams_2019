/*
** EPITECH PROJECT, 2020
** cli
** File description:
** comment
*/

#include "my.h"

int comment_check(char **tab, char *status)
{
    if (strncasecmp(tab[1], "SEND", 4) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "LIST", 4) == 0)
        //appel fonction loggin_client.h list argu manquant
    return (0);
}