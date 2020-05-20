/*
** EPITECH PROJECT, 2020
** src
** File description:
** tools
*/

#include "my.h"

int count_args(char *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == "\"")
            count += 1;
    }
    count = count / 2;
    return (count);
}