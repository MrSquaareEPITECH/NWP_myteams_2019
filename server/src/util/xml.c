/*
** EPITECH PROJECT, 2020
** server
** File description:
** xml.c
*/

#include "xml.h"

xmlNodePtr xml_get_child(xmlNodePtr parent, const xmlChar *name)
{
    for (xmlNodePtr child = parent->children; child; child = child->next)
        if (xmlStrcmp(child->name, name) == 0)
            return (child);
    return (NULL);
}
