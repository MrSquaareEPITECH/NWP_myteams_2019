/*
** EPITECH PROJECT, 2020
** server
** File description:
** xml.c
*/

#include "xml.h"

#include <arrayext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stringext.h>

#include "pcre/pcre.h"

char *xml_format(const char *xml)
{
    char *doc = NULL;
    char **arr = strsplit(xml, "\n");
    char **trim_arr =
        malloc(sizeof(char *) * (arrlen((const void **)(arr)) + 1));

    for (size_t i = 0; arr[i]; ++i)
        trim_arr[i] = strtrim(arr[i], " \t");
    doc = strjoin((const char **)(trim_arr), "");
    arrfree((void **)(trim_arr), free);
    arrfree((void **)(arr), free);
    return (doc);
}

list_t *xml_attributes_create(const char *xml)
{
    list_t *attributes = list_create();
    pcre_find_t find = {4, 2};
    pcre_t *info = pcre_create("([a-zA-Z]+)=\\\"(.*?)\\\"", 0, find);
    pcre_matches_t *m = pcre_match(info, xml, (size_t)(strlen(xml)));

    for (size_t i = 0; m[i + 1] > m[i]; i += 6) {
        xml_attribute_t *attribute = malloc(sizeof(xml_attribute_t));

        printf("m[%ld]: %d\n", i, m[i]);
        printf("m[%ld]: %d\n", i + 1, m[i + 1]);
        printf("m[%ld]: %d\n", i + 2, m[i + 2]);
        printf("m[%ld]: %d\n", i + 3, m[i + 3]);
        printf("m[%ld]: %d\n", i + 4, m[i + 4]);
        printf("m[%ld]: %d\n", i + 5, m[i + 5]);
        attribute->name = strndup(&xml[m[i + 2]], m[i + 3] - m[i + 2]);
        attribute->value = strndup(&xml[m[i + 4]], m[i + 5] - m[i + 4]);
        list_push(attributes, attribute);
    }
    return (attributes);
}

void xml_attribute_delete(xml_attribute_t *attribute)
{
    if (attribute == NULL)
        return;
    free(attribute->name);
    free(attribute->value);
    free(attribute);
}

xml_element_t *xml_element_create(const char *xml)
{
    pcre_find_t find1 = {1, 3};
    pcre_t *pcre =
        pcre_create("<([a-zA-Z_-]+)\\s*(.*?)>(.*?)<\\/\\1?>", 0, find1);
    pcre_matches_t *m = pcre_match(pcre, xml, (size_t)(strlen(xml)));
    long offset = 0;

    if (m[1] <= m[0])
        return (NULL);
    xml_element_t *element = malloc(sizeof(xml_element_t));
    element->name = strndup(&xml[m[2]], m[3] - m[2]);
    char *attributes = strndup(&xml[m[4]], m[5] - m[4]);
    element->content = strndup(&xml[m[6]], m[7] - m[6]);
    element->bounds[0] = m[0];
    element->bounds[1] = m[1];
    element->attributes = xml_attributes_create(attributes);
    element->children = list_create();
    for (xml_element_t *child = xml_element_create(element->content); child;
         offset += child->bounds[1], child = xml_element_create(&element->content[offset])) {
        list_push(element->children, child);
    }
    return (element);
}

void xml_element_delete(xml_element_t *element)
{
    if (element == NULL)
        return;
    free(element->name);
    free(element->content);
    list_delete(element->attributes, delete_c(xml_attribute_delete));
    list_delete(element->children, delete_c(xml_element_delete));
}
