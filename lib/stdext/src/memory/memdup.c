/*
** EPITECH PROJECT, 2020
** EPI_stdext_2019
** File description:
** memdup.c
*/

#include "memoryext.h"

#include <memory.h>
#include <stdlib.h>

void *memdup(const void *src, size_t size)
{
    void *dup = malloc(size);

    if (dup == NULL)
        return (NULL);
    dup = memcpy(dup, src, size);
    return (dup);
}
