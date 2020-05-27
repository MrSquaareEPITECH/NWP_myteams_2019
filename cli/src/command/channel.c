/*
** EPITECH PROJECT, 2020
** cli
** File description:
** channel
*/

#include "my.h"

int channel_check(char **tab, char *status)
{
    if (strncasecmp(tab[1], "CREATE", 6) == 0)
//       client_print_channel_created(tab[4], tab[5], tab[6]);
    if (strncasecmp(tab[1], "EXISTS", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "INFO", 4) == 0)
        client_print_channel(tab[4], tab[5], tab[6]);
    if (strncasecmp(tab[1], "LIST", 4) == 0)
        for (int i = 7; strcasecmp(tab[i + 2], "END") != 0; i =  i + 3)
            client_team_print_channels(tab[i], tab[i + 1], tab[i + 2]);
    return (0);
}