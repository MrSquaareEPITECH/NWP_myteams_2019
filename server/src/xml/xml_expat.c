/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** xml_expat.c
*/

#include "xml_expat.h"

#include <expat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void XMLCALL xml_expat_element_start(
    void *data, const XML_Char *name, const XML_Char **attr)
{
    int *depth = (int *)(data);

    printf("name: %" XML_FMT_STR "\n", name);
    printf("attributes:\n");

    if (*attr == NULL)
        printf("No attribute found.\n");
    for (int i = 0; attr[i]; i += 2)
        printf("- %" XML_FMT_STR "='%" XML_FMT_STR "'\n", attr[i], attr[i + 1]);

    *depth += 1;
}

static void XMLCALL xml_expat_element_content(void *data, const XML_Char *content, int length)
{
    (void)(data);
    (void)(length);

    if (!content || !length)
        return;

    printf("content:\n");
    write(STDOUT_FILENO, content, length);
    printf("\n");
}

static void XMLCALL xml_expat_element_end(void *data, const XML_Char *name)
{
    (void)(name);

    int *depth = (int *)(data);

    *depth -= 1;
}

void xml_expat_print(const char *xml)
{
    XML_Parser parser = XML_ParserCreate(NULL);

    if (!parser) {
        enum XML_Error error = XML_GetErrorCode(parser);

        printf("Parser error: %s\n", XML_ErrorString(error));
    }

    int depth = 0;

    XML_SetUserData(parser, &depth);
    XML_SetElementHandler(
        parser, xml_expat_element_start, xml_expat_element_end);
    XML_SetCharacterDataHandler(parser, xml_expat_element_content);

    if (XML_Parse(parser, xml, (int)(strlen(xml)), 1) == XML_STATUS_ERROR) {
        enum XML_Error error = XML_GetErrorCode(parser);

        printf("Parser error: %s\n", XML_ErrorString(error));
    }

    XML_ParserFree(parser);
}
