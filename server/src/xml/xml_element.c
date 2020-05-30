/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml_element.c
*/

#include "xml_element.h"

#include <string.h>

#include "pcre/pcre.h"
#include "xml_attribute.h"

xml_element_t *xml_element_get(list_t *elements, const char *name)
{
    for (node_t *node = elements->begin; node; node = node->next) {
        xml_element_t *element = (xml_element_t *)(node->obj);

        if (strcmp(element->name, name) == 0)
            return (element);
    }
    return (NULL);
}

xml_element_t *xml_element_parse(const char *xml)
{
    char *regex = "<([a-zA-Z_-]+)\\s*(.*?)>(.*?)<\\/\\1?>";
    pcre_t *pcre = pcre_create(regex, 0, 3);
    int *m = pcre_match(pcre, xml, (size_t)(strlen(xml)));
    xml_element_t *element = NULL;

    if (m[1] > m[0]) {
        char *name = strndup(&xml[m[2]], m[3] - m[2]);
        char *attributes = strndup(&xml[m[4]], m[5] - m[4]);
        char *content = strndup(&xml[m[6]], m[7] - m[6]);
        int bounds[2] = {m[0], m[1]};

        element = xml_element_create(name, attributes, content, bounds);
        free(attributes);
    }
    free(m);
    pcre_delete(pcre);
    return (element);
}

xml_element_t *xml_element_create(
    char *name, char *attributes, char *content, const int *bounds)
{
    xml_element_t *element = malloc(sizeof(xml_element_t));

    if (element == NULL)
        return (NULL);
    element->name = name;
    element->content = content;
    element->attributes = xml_attributes_parse(attributes);
    element->bounds[0] = bounds[0];
    element->bounds[1] = bounds[1];
    element->children = list_create();

    xml_element_t *child = xml_element_parse(element->content);

    for (long offset = 0; child;) {
        list_push(element->children, child);
        offset += child->bounds[1];
        child = xml_element_parse(&element->content[offset]);
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
