/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml.c
*/

#define _GNU_SOURCE

#include "xml.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pcre/pcre.h"

static void xml_element_attributes_empty(xml_element_t *element, int size)
{
    element->attributes = malloc(sizeof(xml_attribute_t *) * (size + 1));
    element->attributes[size] = NULL;
}

static int xml_element_attributes(xml_element_t *element, const char *attr)
{
    if (attr == NULL) {
        xml_element_attributes_empty(element, 0);
        return (0);
    }

    int *matches = pcre_match_loop(
        attr, (int)(strlen(attr)), "([a-zA-Z]+)=\\\"(.*?)\\\"", 4, 2);
    int count = 0;

    for (int i = 2; matches[i + 1] > matches[i]; i += 6, ++count)
        ;

    xml_element_attributes_empty(element, count);

    for (int i = 0, j = 2; i < count; ++i, j += 6) {
        xml_attribute_t *attribute = malloc(sizeof(xml_attribute_t));

        attribute->name =
            strndup(&attr[matches[j]], matches[j + 1] - matches[j]);
        attribute->value =
            strndup(&attr[matches[j + 2]], matches[j + 3] - matches[j + 2]);
        element->attributes[i] = attribute;
    }

    return (0);
}

static int xml_element_content(xml_element_t *element, const char *xml)
{
    char *reg = NULL;
    char *find = NULL;

    asprintf(&reg, "<%s\\s*.*?>", element->name);
    asprintf(&find, "</%s>", element->name);

    int *matches = pcre_match(xml, (int)(strlen(xml)), reg, 0);
    char *end = strstr(xml, find);

    if (matches == NULL)
        return (84);

    if (end > &xml[matches[1]])
        element->content = strndup(&xml[matches[1]], end - &xml[matches[1]]);

    free(reg);
    free(find);

    return (0);
}

xml_element_t *xml_element_create(const char *xml)
{
    xml_element_t *element = malloc(sizeof(xml_element_t));

    if (element == NULL)
        return (NULL);

    int *matches =
        pcre_match(xml, (int)(strlen(xml)), "<([a-zA-Z_-]+)\\s*(.*?)>", 2);

    if (matches == NULL)
        return (NULL);

    if (matches[3] > matches[2])
        element->name = strndup(&xml[matches[2]], matches[3] - matches[2]);

    const char *attributes_raw = NULL;

    if (matches[5] > matches[4])
        attributes_raw = strndup(&xml[matches[4]], matches[5] - matches[4]);

    if (xml_element_attributes(element, attributes_raw))
        return (NULL);
    if (xml_element_content(element, xml))
        return (NULL);

    return element;
}

void xml_element_delete(xml_element_t *element)
{
    if (element == NULL)
        return;

    free(element->name);

    for (int i = 0; element->attributes[i]; ++i)
        free(element->attributes[i]);
    free(element->attributes);

    free(element->content);

    free(element);
}
