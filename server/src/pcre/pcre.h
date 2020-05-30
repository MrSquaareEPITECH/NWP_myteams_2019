/*
** EPITECH PROJECT, 2020
** server
** File description:
** pcre.h
*/

#ifndef SERVER_SRC_PCRE_PCRE_H
#define SERVER_SRC_PCRE_PCRE_H

#include <pcre.h>

typedef struct pcre_s pcre_t;

struct pcre_s {
    pcre *regex;
    pcre_extra *extra;
    int cap;
};

pcre_t *pcre_create(const char *reg, int flags, int cap);
int *pcre_match(pcre_t *pcre, const char *str, int len);
int *pcre_match_all(pcre_t *pcre, const char *str, int len);
void pcre_delete(pcre_t *pcre);

#endif // SERVER_SRC_PCRE_PCRE_H
