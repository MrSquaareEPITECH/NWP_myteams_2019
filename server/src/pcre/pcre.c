/*
** EPITECH PROJECT, 2020
** server
** File description:
** pcre.c
*/

#include "pcre.h"

#include <memory.h>

pcre_t *pcre_create(const char *reg, int flags, pcre_find_t find)
{
    pcre_t *pcre = malloc(sizeof(pcre_t));
    const char *error = NULL;
    int error_offset = 0;

    if (pcre == NULL)
        return (NULL);
    pcre->regex = pcre_compile(reg, flags, &error, &error_offset, NULL);
    if (error)
        return (NULL);
    pcre->extra = pcre_study(pcre->regex, 0, &error);
    if (error)
        return (NULL);
    pcre->find = find;
    return (pcre);
}

pcre_matches_t *pcre_match(pcre_t *pcre, const char *str, int len)
{
    size_t subreal = (pcre->find.max_cap_grp + 1) * 2;
    size_t subsize = (pcre->find.max_cap_grp + 1) * 3;
    size_t size = pcre->find.max_grp * (subreal + 1);
    pcre_matches_t *matches = malloc(sizeof(pcre_matches_t) * size);
    pcre_matches_t *submatches = malloc(sizeof(pcre_matches_t) * subsize);
    size_t i = 0;
    int offset = 0;

    memset(matches, 0, sizeof(pcre_matches_t) * size);
    do {
        size_t j = 0;

        memset(submatches, 0, sizeof(pcre_matches_t) * subsize);
        pcre_exec(pcre->regex, pcre->extra, str, len, offset, 0, submatches, subsize);
        for (; (j < subreal) && (submatches[j + 1] > submatches[j]); j += 2) {
            matches[i + j] = submatches[j];
            matches[i + j + 1] = submatches[j + 1];
        }
        offset = submatches[1];
        i += j;
    } while ((i < size) && (submatches[1] > submatches[0]));
    free(submatches);
    return (matches);
}

void pcre_delete(pcre_t *pcre)
{
    if (pcre == NULL)
        return;
    pcre_free(pcre->regex);
    pcre_free_study(pcre->extra);
    free(pcre);
}
