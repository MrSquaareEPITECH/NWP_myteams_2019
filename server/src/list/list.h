/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** list.h
*/

#ifndef NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_H
#define NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_H

#include <stdbool.h>

typedef struct list_s list_t;
typedef struct node_s node_t;

typedef bool (*compare_t)(void *obj, void *prop);
typedef void (*delete_t)(void *obj);

#define compare_c(func_ptr) ((compare_t)(func_ptr))
#define delete_c(func_ptr) ((delete_t)(func_ptr))

struct node_s {
    void *obj;
    node_t *next;
};

struct list_s {
    node_t *begin;
    node_t *end;
};

list_t *list_create(void);
void *list_get(list_t *this, void *prop, compare_t compare);
int list_push(list_t *this, void *obj);
void list_delete(list_t *this, delete_t delete);

#endif // NWP_MYTEAMS_2019_SERVER_SRC_LIST_LIST_H
