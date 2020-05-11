/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>

#include "team/team_list.h"
#include "team/team_list_xml.h"

int main(void)
{
    team_list_t *teams = team_list_create();
    team_t *team = team_create("my_teams", "Save us from the lock down");
    channel_t *channel = channel_create("general", "General communication");
    thread_t *thread1 = thread_create("Hello, World!", "A simple hello");
    thread_t *thread2 = thread_create("Follow Up", "Thread about the follow up");
    comment_t *comment1 = comment_create("Hello, Admin!");
    comment_t *comment2 = comment_create("Thanks!");
    comment_t *comment3 = comment_create("Are we ready?");
    comment_t *comment4 = comment_create("No.");

    thread1->comments->push(thread1->comments, comment1);
    thread1->comments->push(thread1->comments, comment2);
    thread2->comments->push(thread2->comments, comment3);
    thread2->comments->push(thread2->comments, comment4);
    channel->threads->push(channel->threads, thread1);
    channel->threads->push(channel->threads, thread2);
    team->channels->push(team->channels, channel);
    teams->push(teams, team);

    char *xml = team_list_xml_export(teams);

    printf("%s\n", xml);

    team_list_delete(teams);
}
