/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** strpbrkn.c
*/

#include <string.h>

#include "stringext.h"

char *strpbrkn(const char *str, const char *reject)
{
    str += strspn(str, reject);
    return (*str ? (char *)(str) : NULL);
}
