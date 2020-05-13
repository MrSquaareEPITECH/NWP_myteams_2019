/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml_libxml2.c
*/

#include "xml_libxml2.h"

// ln -s /usr/include/libxml2/libxml /usr/include/libxml

#include <libxml/tree.h>
#include <string.h>

static void xml_libxml2_print_r(xmlNodePtr node)
{
    if (node->type == XML_ELEMENT_NODE) {
        printf("name: %s\n", node->name);
        printf("attributes:\n");

        if (node->properties == NULL)
            printf("No attribute found.\n");
        for (xmlAttrPtr current = node->properties; current;
             current = current->next)
            printf("- %s='%s'\n", current->name,
                xmlNodeListGetString(node->doc, current->children, 1));
        printf("\n");
    }

    printf("content:\n");
    if (node->content == NULL)
        printf("No content.\n");
    else
        printf("%s\n", node->content);

    if (node->children)
        xml_libxml2_print_r(node->children);
    if (node->next)
        xml_libxml2_print_r(node->next);
}

void xml_libxml2_print(const char *xml)
{
    LIBXML_TEST_VERSION

    xmlDocPtr doc = xmlReadMemory(xml, (int)(strlen(xml)), NULL, NULL, 0);

    xmlNodePtr root = xmlDocGetRootElement(doc);

    xml_libxml2_print_r(root);

    xmlFreeDoc(doc);
}
