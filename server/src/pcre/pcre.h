/*
** EPITECH PROJECT, 2020
** server
** File description:
** pcre.h
*/

#ifndef SERVER_SRC_PCRE_PCRE_H
#define SERVER_SRC_PCRE_PCRE_H

#include <pcre.h>

typedef int pcre_matches_t;
typedef struct pcre_find_s pcre_find_t;
typedef struct pcre_s pcre_t;

struct pcre_find_s {
    int max_grp;
    int max_cap_grp;
};

struct pcre_s {
    pcre *regex;
    pcre_extra *extra;
    pcre_find_t find;
};

pcre_t *pcre_create(const char *reg, int flags, pcre_find_t opt);
pcre_matches_t *pcre_match(pcre_t *pcre, const char *str, int len);
void pcre_delete(pcre_t *pcre);

#endif // SERVER_SRC_PCRE_PCRE_H
