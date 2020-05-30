/*
** EPITECH PROJECT, 2020
** server
** File description:
** xml_file.c
*/

#include "xml_file.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

#include "xml_internal.h"

char *xml_from_file(const char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (NULL);

    size_t len = lseek(fd, 0, SEEK_END);
    char *str = mmap(0, len, PROT_READ, MAP_PRIVATE, fd, 0);
    char *xml = xml_format(str);

    close(fd);
    return (xml);
}
