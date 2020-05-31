/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_xml.c
*/

#include "server_load.h"

#include <stddef.h>

#include "exchange/exchange_xml.h"
#include "list/list_xml.h"
#include "team/team_xml.h"
#include "user/user_xml.h"
#include "xml/xml_element.h"
#include "xml/xml_file.h"

static list_t *server_load_teams(void)
{
    list_t *list = NULL;
    char *xml = xml_from_file("teams.xml");

    if (xml == NULL) {
        list = list_create();
    } else {
        xml_element_t *element = xml_element_parse(xml);

        list = list_xml_import(element, (import_t)(team_xml_import));
    }
    return (list);
}

static list_t *server_load_exchanges(void)
{
    list_t *list = NULL;
    char *xml = xml_from_file("exchanges.xml");

    if (xml == NULL) {
        list = list_create();
    } else {
        xml_element_t *element = xml_element_parse(xml);

        list = list_xml_import(element, (import_t)(exchange_xml_import));
    }
    return (list);
}

static list_t *server_load_users(void)
{
    list_t *list = NULL;
    char *xml = xml_from_file("users.xml");

    if (xml == NULL) {
        list = list_create();
    } else {
        xml_element_t *element = xml_element_parse(xml);

        list = list_xml_import(element, (import_t)(user_xml_import));
    }
    return (list);
}

void server_load(server_t *server)
{
    server->teams = server_load_teams();
    server->exchanges = server_load_exchanges();
    server->users = server_load_users();
}
