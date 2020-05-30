/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exchange/exchange_xml.h"
#include "list/list_xml.h"
#include "team/team_xml.h"
#include "user/user_xml.h"
#include "xml/xml_element.h"
#include "xml/xml_file.h"
#include "xml/xml_memory.h"

void test_teams_xml()
{
    char *xml1 = xml_from_file("teams.xml");
    xml_element_t *root1 = xml_element_parse(xml1);
    list_t *teams1 = list_xml_import(root1, (import_t)(team_xml_import));
    char *export =
        list_xml_export(teams1, "", "teams", (export_t)(team_xml_export));
    char *xml2 = xml_from_memory(export);
    xml_element_t *root2 = xml_element_parse(xml2);
    list_t *teams2 = list_xml_import(root2, (import_t)(team_xml_import));
    char *export2 =
        list_xml_export(teams2, "", "teams", (export_t)(team_xml_export));

    printf("%s", export);
    printf("%s", export2);
    printf("strcmp: %d\n", strcmp(export, export2));
}

void test_exchanges_xml()
{
    char *xml1 = xml_from_file("exchanges.xml");
    xml_element_t *root1 = xml_element_parse(xml1);
    list_t *exchanges1 =
        list_xml_import(root1, (import_t)(exchange_xml_import));
    char *export = list_xml_export(
        exchanges1, "", "exchanges", (export_t)(exchange_xml_export));
    char *xml2 = xml_from_memory(export);
    xml_element_t *root2 = xml_element_parse(xml2);
    list_t *exchanges2 =
        list_xml_import(root2, (import_t)(exchange_xml_import));
    char *export2 = list_xml_export(
        exchanges2, "", "exchanges", (export_t)(exchange_xml_export));

    printf("%s", export);
    printf("%s", export2);
    printf("strcmp: %d\n", strcmp(export, export2));
}

void test_users_xml()
{
    char *xml1 = xml_from_file("users.xml");
    xml_element_t *root1 = xml_element_parse(xml1);
    list_t *users1 = list_xml_import(root1, (import_t)(user_xml_import));
    char *export =
        list_xml_export(users1, "", "users", (export_t)(user_xml_export));
    char *xml2 = xml_from_memory(export);
    xml_element_t *root2 = xml_element_parse(xml2);
    list_t *users2 = list_xml_import(root2, (import_t)(user_xml_import));
    char *export2 =
        list_xml_export(users2, "", "users", (export_t)(user_xml_export));

    printf("%s", export);
    printf("%s", export2);
    printf("strcmp: %d\n", strcmp(export, export2));
}

int main(void)
{
    test_teams_xml();
    test_exchanges_xml();
    test_users_xml();
    return (0);
}
