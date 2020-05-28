/*
** EPITECH PROJECT, 2020
** cli
** File description:
** str_to_word_array
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *str_cpy_range(char *str, int start, int end)
{
    int j = 0;
    int i = start;
    char *dest = NULL;

    dest = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (dest == NULL)
        exit(84);
    while (i != end) {
        dest[j] = str[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return (dest);
}

int str_split_count(char *str, char chr)
{
    int i = 0;
    int count = 0;

    while (str && (str[i] != '\0')) {
        for (i += 0; str[i] == chr; ++i) ;
        count += (str[i] != '\0') ? 1 : 0;
        for (i += 0; (str[i] != chr) && (str[i] != '\0'); ++i) ;
    }
    return (count);
}

char **str_split(char *str, char chr)
{
    int from = 0;
    int to = 0;
    int size = str_split_count(str, chr);
    char **list = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i < size; ++i) {
        for (from = to; str[from] == chr; ++from);
        for (to = from; (str[to] != chr) && (str[to] != '\0'); ++to);
        list[i] = str_cpy_range(str, from, to);
    }
    if (list[size - 1][0] == '\n') {
        list[size - 1] = NULL;
        return (list);
    }
    list[size] = NULL;
    return (list);
}

char **replace_char_double_array(char **tab, char c)
{
    for (int i = 0 ; tab[i] != NULL ; i++) {
        for (int j = 0 ; tab[i][j] != '\0' ; j++) {
            if (tab[i][j] == c)
                tab[i][j] = '\0';
        }
    }
    return (tab);
}