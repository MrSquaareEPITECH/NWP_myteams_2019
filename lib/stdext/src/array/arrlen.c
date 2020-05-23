/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** arrlen.c
*/

#include "arrayext.h"

size_t arrlen(const void **arr)
{
    size_t len = 0;

    for (; arr[len]; ++len) ;
    return (len);
}
