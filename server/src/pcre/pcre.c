/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** pcre.c
*/

#include "pcre.h"

#include <pcre.h>
#include <string.h>

static int *pcre_match_exec(
    pcre *regex, pcre_extra *extra, const char *str, int len, int offset, int maxCapGrp)
{
    int size = (maxCapGrp + 1) * 3;
    int *matches = malloc(sizeof(int) * size);

    memset(matches, 0, sizeof(int) * size);
    pcre_exec(regex, extra, str, len, offset, PCRE_NEWLINE_ANY, matches, size);

    return (matches);
}

int *pcre_match(const char *str, int len, const char *reg, int max_cap_grp)
{
    pcre *regex = NULL;
    pcre_extra *extra = NULL;
    const char *error = NULL;
    int errorOffset = 0;

    regex = pcre_compile(reg, 0, &error, &errorOffset, NULL);

    if (regex == NULL)
        return (NULL);

    int *matches = pcre_match_exec(regex, extra, str, len, 0, max_cap_grp);

    pcre_free_study(extra);
    pcre_free(regex);

    return matches;
}

int *pcre_match_loop(
    const char *str, int len, const char *reg, int max_grp, int max_cap_grp)
{
    pcre *regex = NULL;
    pcre_extra *extra = NULL;
    const char *error = NULL;
    int errorOffset = 0;

    regex = pcre_compile(reg, 0, &error, &errorOffset, NULL);

    if (regex == NULL)
        return (NULL);

    int size = max_grp * ((max_cap_grp + 1) * 3);
    int *matchesLoop = malloc(sizeof(int) * size);

    int *matches = NULL;
    int offset = 0;
    int iLoop = 0;

    do {
        matches = pcre_match_exec(regex, extra, str, len, offset, max_cap_grp);
        int real_cap = 0;

        for (int i = 0; (i < ((max_cap_grp + 1) * 2)) && (matches[i + 1] > matches[i]); i += 2, ++real_cap) {
            matchesLoop[iLoop + i] = matches[i];
            matchesLoop[iLoop + i + 1] = matches[i + 1];
        }

        offset = matches[1];
        iLoop += real_cap * 2;
    } while (matches[1] > matches[0]);

    pcre_free_study(extra);
    pcre_free(regex);

    return matchesLoop;
}
