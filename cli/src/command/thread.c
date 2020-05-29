/*
** EPITECH PROJECT, 2020
** cli
** File description:
** thread
*/

#include "my.h"
#include "logging_client.h"

int thread_check(char **tab, char *status)
{
    if (strncasecmp(tab[1], "CREATE", 6) == 0) {
        client_print_thread_created(tab[4], tab[5], atoi(tab[6]),
            tab[7], tab[8]);
    }
    if (strncasecmp(tab[1], "EXISTS", 6) == 0)
        printf("%s %s %s %s : %s\n", tab[0], tab[1], tab[2], tab[3], status);
    if (strncasecmp(tab[1], "INFO", 4) == 0)
        client_print_thread(tab[4], tab[5], atoi(tab[6]), tab[7], tab[8]);
    if (strncasecmp(tab[1], "LIST", 4) == 0) {
        for (int i = 7; strcasecmp(tab[i + 4], "END") != 0; i = i + 5) {
            client_channel_print_threads(tab[4], tab[5], atoi(tab[6]),
                tab[7], tab[8]);
        }
    }
    return (0);
}
