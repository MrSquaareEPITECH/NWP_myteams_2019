/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** pcre_internal.c
*/

#include "pcre_internal.h"

int pcre_match_all_count(pcre_t *pcre, const char *str, int len)
{
    size_t count = 0;
    size_t size = (pcre->cap + 1) * 3;
    int *matches = malloc(sizeof(int) * size);
    int rc = pcre_exec(pcre->regex, pcre->extra, str, len, 0, 0, matches, size);

    for (; rc >= 0; ++count) {
        rc = pcre_exec(
            pcre->regex, pcre->extra, str, len, matches[1], 0, matches, size);
    }
    free(matches);
    return (count);
}

void
