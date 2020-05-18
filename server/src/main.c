/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main.c
*/

#include <libxml/tree.h>

#include "channel/channel.h"
#include "comment/comment.h"
#include "list/list.h"
#include "list/list_xml.h"
#include "message/message.h"
#include "private/private.h"
#include "subscriber/subscriber.h"
#include "team/team.h"
#include "team/team_xml.h"
#include "thread/thread.h"
#include "user/user.h"
#include "user/user_xml.h"

int main(void)
{
    list_t *users = list_create();
    user_t *user1 = user_create("Guillaume Bonnet");
    user_t *user2 = user_create("Dorian Duval");
    user_t *user3 = user_create("Quentin Muratorio");
    private_t *private1 = private_create(user2->uuid);
    private_t *private2 = private_create(user3->uuid);
    message_t *message1 =
        message_create("Imminent launch of the Ariane 6 rocket");
    message_t *message2 = message_create("Confronts the trees");
    list_t *teams = list_create();
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

    list_push(private1->messages, message1);
    list_push(private2->messages, message2);
    list_push(user1->privates, private1);
    list_push(user1->privates, private2);
    list_push(users, user1);
    list_push(users, user2);
    list_push(users, user3);
    list_push(thread1->comments, comment1);
    list_push(thread1->comments, comment2);
    list_push(thread2->comments, comment3);
    list_push(thread2->comments, comment4);
    list_push(channel->threads, thread1);
    list_push(channel->threads, thread2);
    list_push(team->channels, channel);
    list_push(team->subscribers, subscriber);
    list_push(teams, team);

    // Export as teams.xml

    xmlDocPtr doc = xmlNewDoc(NULL);
    xmlNodePtr root = xmlNewNode(NULL, BAD_CAST "teams");

    root = list_xml_export(teams, root, export_c(team_xml_export));
    xmlDocSetRootElement(doc, root);

    xmlSaveFormatFile("teams.xml", doc, 1);

    xmlFreeDoc(doc);
    list_delete(teams, delete_c(team_delete));

    // Export as users.xml

    doc = xmlNewDoc(NULL);
    root = xmlNewNode(NULL, BAD_CAST "users");

    root = list_xml_export(users, root, export_c(user_xml_export));
    xmlDocSetRootElement(doc, root);

    xmlSaveFormatFile("users.xml", doc, 1);

    xmlFreeDoc(doc);
    list_delete(users, delete_c(user_delete));

    // Import teams.xml and export as teams2.xml

    doc = xmlReadFile("teams.xml", NULL, 0);
    root = xmlDocGetRootElement(doc);

    teams = list_xml_import(root, "team", import_c(team_xml_import));

    xmlFreeDoc(doc);

    doc = xmlNewDoc(NULL);
    root = xmlNewNode(NULL, BAD_CAST "teams");

    root = list_xml_export(teams, root, export_c(team_xml_export));
    xmlDocSetRootElement(doc, root);

    xmlSaveFormatFile("teams2.xml", doc, 1);

    xmlFreeDoc(doc);
    list_delete(teams, delete_c(team_delete));

    // Import users.xml and export as users2.xml

    doc = xmlReadFile("users.xml", NULL, 0);
    root = xmlDocGetRootElement(doc);

    users = list_xml_import(root, "user", import_c(user_xml_import));

    xmlFreeDoc(doc);

    doc = xmlNewDoc(NULL);
    root = xmlNewNode(NULL, BAD_CAST "users");

    root = list_xml_export(users, root, export_c(user_xml_export));
    xmlDocSetRootElement(doc, root);

    xmlSaveFormatFile("users2.xml", doc, 1);

    xmlFreeDoc(doc);
    list_delete(users, delete_c(user_delete));
}
