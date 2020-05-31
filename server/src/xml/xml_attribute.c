/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml_attribute.c
*/

#include "xml_attribute.h"

#include <string.h>

#include "pcre/pcre.h"

char *xml_attributes_get(list_t *attributes, const char *name)
{
    for (node_t *node = attributes->begin; node; node = node->next) {
        xml_attribute_t *attribute = (xml_attribute_t *)(node->obj);

        if (strcmp(attribute->name, name) == 0)
            return (attribute->value);
    }
    return (NULL);
}

list_t *xml_attributes_parse(const char *xml)
{
    list_t *attributes = list_create();
    char *regex = "([a-zA-Z]+)=\\\"(.*?)\\\"";
    pcre_t *pcre = pcre_create(regex, 0, 2);
    int *m = pcre_match_all(pcre, xml, (size_t)(strlen(xml)));

    for (size_t i = 0; m[i] != -1; i += 6) {
        char *name = strndup(&xml[m[i + 2]], m[i + 3] - m[i + 2]);
        char *value = strndup(&xml[m[i + 4]], m[i + 5] - m[i + 4]);
        xml_attribute_t *attribute = xml_attribute_create(name, value);

        list_push(attributes, attribute);
    }
    free(m);
    pcre_delete(pcre);
    return (attributes);
}

xml_attribute_t *xml_attribute_create(char *name, char *value)
{
    xml_attribute_t *attribute = malloc(sizeof(xml_attribute_t));

    if (attribute == NULL)
        return (NULL);
    attribute->name = name;
    attribute->value = value;
    return (attribute);
}

void xml_attribute_delete(xml_attribute_t *attribute)
{
    if (attribute == NULL)
        return;
    free(attribute->name);
    free(attribute->value);
    free(attribute);
}
