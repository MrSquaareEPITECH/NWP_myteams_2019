/*
** EPITECH PROJECT, 2020
** cli
** File description:
** user
*/

#include "my.h"

int user_check(char **tab, char *status)
{
    if (strncasecmp(tab[1], "LOGIN", 5) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "EXISTS", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "INFO", 4) == 0)
//        client_print_user(tab[4], tab[5], 0);
    if (strncasecmp(tab[1], "LIST", 4) == 0)
        //appel fonction loggin_client.h list
    if (strncasecmp(tab[1], "LOGOUT", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "SUBSCRIBE", 9) == 0)
        client_print_subscribed(tab[4], tab[5]);
    if (strncasecmp(tab[1], "SUBSCRIBTION", 12) == 0)
        //appel fonction loggin_client.h subscribtion
    if (strncasecmp(tab[1], "UNSUBSCRIBE", 11) == 0)
        client_print_unsubscribed(tab[4], tab[5]);
    return (0);
}