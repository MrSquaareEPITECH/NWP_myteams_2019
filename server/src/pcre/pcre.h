/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** pcre.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_PCRE_PCRE_H
#define NWP_MYTEAMS_2019_SERVER_SRC_PCRE_PCRE_H

int *pcre_match(const char *str, int len, const char *reg, int max_cap_grp);
int *pcre_match_loop(const char *str, int len, const char *reg, int max_grp, int max_cap_grp);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_PCRE_PCRE_H
