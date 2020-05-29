/*
** EPITECH PROJECT, 2020
** src
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include "logging_client.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>

#define SIZE_OF_BUFFER (1024)
#define ERROR_FUNCTION (-1)
#define SUCCESS (0)
#define ERROR (84)

static const char * const HELP[] = {"./help : show help\n",
    "./login [“username”] : set the username used by client\n",
    "./logout : disconnect the client from the server\n",
    "./users : get the list of all users that exist on the domain\n",
    "./user [“user_uuid”] : get information about a user\n",
    "./send [“user_uuid”] [“message_body”] : send a message to a user\n",
    "./messages [“user_uuid”] : list all messages exchange with an user\n",
    "./subscribe [“team_uuid”] : subscribe to the event of a team and its",
    " sub directories (enable receptionof all events from a team)\n",
    "./subscribed ?[“team_uuid”] : list all subscribed teams or list all",
    " users subscribed to a team\n./unsubscribe [“team_uuid”] : ",
    "unsubscribe from a team\n./use ?[“team_uuid”] ?[“channel_uuid”] ",
    "?[“thread_uuid”] : use specify a context team/channel/thread\n",
    "./create : based on what is being used create the sub resource",
    " (see below)\n./list : based on what is being used list all the ",
    "sub resources (see below)\n./info : based on what is being used",
    "list the current (see below)\n"};

typedef struct client_s {
    int port;
    int fd_client;
    char *buffer;
    struct sockaddr_in sin;
} client_t;

typedef struct utilities_s {
    fd_set set_read;
    fd_set a_read;
    fd_set set_write;
    fd_set a_write;
} utilities_t;

/*
structure server
-socket
-select
-messageQ
*/

/* str_to_word_array */
char **str_split(char *str, char chr);
char **replace_char_double_array(char **tab, char c);

/* read.c */
char *get_command(void);
void check_command(client_t *cli);

/* sort_command.c */
void display_help();
int count_args(char *str);
int count_lines(char *str);
char *take_word(char *str, int i);
char *replace_char_array(char *str, char c);

/* handle_command.c */
void handle_user(client_t *cli);
void handle_send(client_t *cli);
void handle_login(client_t *cli);
void handle_create(client_t *cli);
void handle_subscribe(client_t *cli, bool i);

/* server.c */
int get_info_server(client_t *cli);

/* command folder */
int user_check(char **tab, char *status);
int team_check(char **tab, char *status);
int thread_check(char **tab, char *status);
int channel_check(char **tab, char *status);
int comment_check(char **tab, char *status);
int message_check(char **tab, char *status);
char *check_status(char *word);

/* send_to_lib.c */
void parse_msg(char *str);

#endif /* !MY_H_ */
