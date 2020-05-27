/*
** EPITECH PROJECT, 2020
** cli
** File description:
** thread
*/

#include "my.h"

int thread_check(char **tab, char *status)
{
    if (strncasecmp(tab[1], "CREATE", 6) == 0)
        //appel fonction loggin_client.h create
    if (strncasecmp(tab[1], "EXISTS", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "INFO", 4) == 0)
        //appel fonction loggin_client.h info
    if (strncasecmp(tab[1], "LIST", 4) == 0)
        //appel fonction loggin_client.h list 5 attendus 4 donnés
    return (0);
}