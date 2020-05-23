/*
** EPITECH PROJECT, 2020
** src
** File description:
** handle_command
*/

#include "my.h"

void display_help()
{
    for (int i = 0; i != 13; i++)
        printf("%s", HELP[i]);
    write(0, "\n", 2);
}

int count_args(char *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\"')
            count += 1;
    }
    count = count / 2;
    return (count);
}