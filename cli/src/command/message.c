/*
** EPITECH PROJECT, 2020
** cli
** File description:
** message
*/

#include "my.h"
#include "logging_client.h"

int message_check(char **tab, char *status)
{
    if (strncasecmp(tab[1], "EXISTS", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "SEND", 4) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "LIST", 4) == 0) {
        for (int i = 7; strcasecmp(tab[i + 2], "END") != 0; i = i + 3) {
            client_private_message_print_messages(tab[4], atoi(tab[5]),
                tab[6]);
        }
    }
    return (0);
}
