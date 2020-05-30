/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_save.c
*/

#include "server_save.h"

#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#include "exchange/exchange_xml.h"
#include "list/list_xml.h"
#include "team/team_xml.h"
#include "user/user_xml.h"

void server_save_teams(server_t *server)
{
    int fd = open("teams.xml", O_WRONLY | O_CREAT | O_TRUNC, 644);

    if (fd == -1)
        return;

    char *xml = list_xml_export(
        server->teams, "", "teams", (export_t)(team_xml_export));

    write(fd, xml, strlen(xml));
    close(fd);
}

void server_save_exchanges(server_t *server)
{
    int fd = open("exchanges.xml", O_WRONLY | O_CREAT | O_TRUNC, 644);

    if (fd == -1)
        return;

    char *xml = list_xml_export(
        server->exchanges, "", "exchanges", (export_t)(exchange_xml_export));

    write(fd, xml, strlen(xml));
    close(fd);
}

void server_save_users(server_t *server)
{
    int fd = open("users.xml", O_WRONLY | O_CREAT | O_TRUNC, 644);

    if (fd == -1)
        return;

    char *xml = list_xml_export(
        server->users, "", "users", (export_t)(user_xml_export));

    write(fd, xml, strlen(xml));
    close(fd);
}

void server_save(server_t *server)
{
    server_save_teams(server);
    server_save_exchanges(server);
    server_save_users(server);
}
