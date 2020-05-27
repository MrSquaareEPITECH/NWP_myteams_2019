/*
** EPITECH PROJECT, 2020
** cli
** File description:
** team
*/

#include "my.h"

int team_check(char **tab, char *status)
{
    if (strncasecmp(tab[1], "CREATE", 6) == 0)
        //appel fonction loggin_client.h create
    if (strncasecmp(tab[1], "EXISTS", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "INFO", 4) == 0)
        client_print_team(tab[4], tab[5], tab[6]);
    if (strncasecmp(tab[1], "LIST", 4) == 0)
        // client_team_print_channels();
    if (strncasecmp(tab[1], "SUBSCRIBERS", 11) == 0)
        //appel fonction loggin_client.h subscribers pas de fonciton
    return (0);
}