/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** string.h
*/

#ifndef EPI_STDEXT_2019_INCLUDE_STRINGEXT_H
#define EPI_STDEXT_2019_INCLUDE_STRINGEXT_H

// strchr
char *strchrn(const char *str, char chr);
char *strrchrn(const char *str, char chr);

// strjoin
char *strjoin(const char **arr, const char *delim);

// strpbrk
char *strrpbrk(const char *str, const char *accept);
char *strpbrkn(const char *str, const char *reject);
char *strrpbrkn(const char *str, const char *reject);

// strrem
char *strrem(char *str, const char *list);

// strrev
char *strrev(char *str);

// strsplit
char **strsplit(const char *str, const char *delim);
char **strsplitj(const char *str, const char *delim, const char *jump);

// strstr
char *strrstr(const char *str, const char *needle);
char *strstrn(const char *str, const char *needle);
char *strrstrn(const char *str, const char *needle);

// strtrim
char *strtrim(const char *str, const char *list);
char *strltrim(const char *str, const char *list);
char *strrtrim(const char *str, const char *list);

#endif // EPI_STDEXT_2019_INCLUDE_STRINGEXT_H
