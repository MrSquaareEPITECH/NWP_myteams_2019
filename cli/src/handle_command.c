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