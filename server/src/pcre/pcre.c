/*
** EPITECH PROJECT, 2020
** server
** File description:
** pcre.c
*/

#include "pcre.h"

#include <memory.h>

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

int *pcre_match(pcre_t *pcre, const char *str, int len)
{
    size_t max = (pcre->cap + 1) * 2;
    size_t size = (pcre->cap + 1) * 3;
    int *matches = malloc(sizeof(int) * size);

    if (pcre_exec(pcre->regex, pcre->extra, str, len, 0, 0, matches, size) >=
        0) {
        matches[max] = -1;
        matches[max + 1] = -1;
    }
    return (matches);
}

int *pcre_match_all(pcre_t *pcre, const char *str, int len)
{
    size_t subsize = (pcre->cap + 1) * 3;
    size_t submax = (pcre->cap + 1) * 2;
    size_t count = pcre_match_all_count(pcre, str, len);
    size_t size = subsize * count;
    size_t max = submax * count;
    int *submatches = malloc(sizeof(int) * subsize);
    int *matches = malloc(sizeof(int) * (size + 2));
    int rc = pcre_exec(
        pcre->regex, pcre->extra, str, len, 0, 0, submatches, subsize);

    for (size_t i = 0; rc >= 0; i += submax) {
        for (size_t j = 0; j < submax; j += 2) {
            matches[i + j] = submatches[j];
            matches[i + j + 1] = submatches[j + 1];
        }
        rc = pcre_exec(pcre->regex, pcre->extra, str, len, submatches[1], 0,
            submatches, subsize);
    }
    free(submatches);
    matches[max] = -1;
    matches[max + 1] = -1;
    return (matches);
}

pcre_t *pcre_create(const char *reg, int flags, int cap)
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
    pcre->cap = cap;
    return (pcre);
}

void pcre_delete(pcre_t *pcre)
{
    if (pcre == NULL)
        return;
    pcre_free(pcre->regex);
    pcre_free_study(pcre->extra);
    free(pcre);
}
