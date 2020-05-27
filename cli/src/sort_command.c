/*
** EPITECH PROJECT, 2020
** src
** File description:
** handle_command
*/

#include "my.h"

void display_help(void)
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

int count_lines(char *str)
{
    int lines = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\n')
            lines++;
    return (lines);
}

char *take_word(char *str, int i)
{
    char *word = NULL;

    word = malloc(sizeof(char) * strlen(str));
    if (str[i] == ' ' && str[i] != '\0')
        i++;
    for (; str[i] != '\0' ; i++) {
        word[i] = str[i];
        if (str[i] == ' ')
            break;
    }
    word[i] = '\0';
    return (word);
}

char *replace_char_array(char *str, char c)
{
    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] == c)
            str[i] = ' ';
    }
    return (str);
}