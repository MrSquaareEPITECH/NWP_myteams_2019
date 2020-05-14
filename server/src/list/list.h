/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_H

#include <stdbool.h>

#include "channel/channel.h"
#include "client/client.h"
#include "comment/comment.h"
#include "message/message.h"
#include "private/private.h"
#include "subscriber/subscriber.h"
#include "team/team.h"
#include "thread/thread.h"
#include "user/user.h"

#define channel(obj) ((channel_t *)(obj))
#define client(obj) ((client_t *)(obj))
#define comment(obj) ((comment_t *)(obj))
#define message(obj) ((message_t *)(obj))
#define private(obj) ((private_t *)(obj))
#define subscriber(obj) ((subscriber_t *)(obj))
#define team(obj) ((team_t *)(obj))
#define thread(obj) ((thread_t *)(obj))
#define user(obj) ((user_t *)(obj))

typedef struct list_s list_t;
typedef struct node_s node_t;

typedef bool (*compare_t)(void *obj, void *prop);
typedef void (*delete_t)(void *obj);

#define compare(func_ptr) ((compare_t)(func_ptr))
#define delete(func_ptr) ((delete_t)(func_ptr))

struct node_s {
    void *obj;
    node_t *next;
};

struct list_s {
    node_t *begin;
    node_t *end;

    void *(*get)(list_t *this, void *prop, compare_t compare);
    int (*push)(list_t *this, void *obj);
};

list_t *list_create(void);
void list_delete(list_t *this, delete_t delete);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_H
