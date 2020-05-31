/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** arrayext.h
*/

#ifndef EPI_STDEXT_2019_INCLUDE_ARRAYEXT_H
#define EPI_STDEXT_2019_INCLUDE_ARRAYEXT_H

#include <stddef.h>

typedef void (*delete_t)(void *obj);
typedef void *(*duplicate_t)(const void *obj);

void **arrdup(const void **arr, duplicate_t duplicate);
void arrfree(void **arr, delete_t delete);
size_t arrlen(const void **arr);

#endif // EPI_STDEXT_2019_INCLUDE_ARRAYEXT_H
