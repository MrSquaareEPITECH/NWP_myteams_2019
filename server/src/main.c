/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <stdio.h>

#include "team/team_list.h"
#include "team/team_list_xml.h"
#include "user/user_list.h"
#include "user/user_list_xml.h"

int main(void)
{
    user_list_t *users = user_list_create();
    user_t *user1 = user_create("Guillaume Bonnet");
    user_t *user2 = user_create("Dorian Duval");
    user_t *user3 = user_create("Quentin Muratorio");
    private_t *private1 = private_create(user2->uuid);
    private_t *private2 = private_create(user3->uuid);
    message_t *message1 =
        message_create("Imminent launch of the Ariane 6 rocket");
    message_t *message2 = message_create("Confronts the trees");
    team_list_t *teams = team_list_create();
    team_t *team = team_create("my_teams", "Save us from the lock down");
    subscriber_t *subscriber = subscriber_create(user1->uuid);
    channel_t *channel = channel_create("general", "General communication");
    thread_t *thread1 = thread_create("Hello, World!", "A simple hello");
    thread_t *thread2 =
        thread_create("Follow Up", "Thread about the follow up");
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
    team->subscribers->push(team->subscribers, subscriber);
    teams->push(teams, team);
    private1->messages->push(private1->messages, message1);
    private2->messages->push(private2->messages, message2);
    user1->privates->push(user1->privates, private1);
    user1->privates->push(user1->privates, private2);
    users->push(users, user1);
    users->push(users, user2);
    users->push(users, user3);

    char *xml1 = team_list_xml_export(teams);

    printf("%s\n", xml1);

    char *xml2 = user_list_xml_export(users);

    printf("%s\n", xml2);

    team_list_delete(teams);
}
