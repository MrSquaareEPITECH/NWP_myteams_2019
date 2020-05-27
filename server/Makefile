##
## EPITECH PROJECT, 2019
## NWP_myteams_2019
## File description:
## Makefile
##

NAME				=		myteams_server
TEST_NAME			=		tests/unit_tests
TEST_SH_NAME		=		tests/tests.sh

COV_DIR				=		obj
INCL_DIR			=		src
OBJ_DIR				=		obj
SRC_DIR				=		src
TEST_DIR			=		tests

LIB_SOCKET_DIR		=		../lib/socket
LIB_STDEXT_DIR		=		../lib/stdext

AR					=		ar rcs
CC					=		gcc
RM					=		rm -rf

CFLAGS				+=		-I $(LIB_SOCKET_DIR)/include
CFLAGS				+=		-I $(LIB_STDEXT_DIR)/include

LDFLAGS				+=		-L $(LIB_SOCKET_DIR) -lsocket
LDFLAGS				+=		-L $(LIB_STDEXT_DIR) -lstdext
LDLIBS				+=		-luuid

MAIN_SRC			=		main.c

PROJ_SRC			=		channel/channel.c						\
							channel/channel_util.c					\
							client/client.c							\
							client/client_util.c					\
							command/command.c						\
							command/command_util.c					\
							command/create/create_channel.c			\
							command/create/create_comment.c			\
							command/create/create_team.c			\
							command/create/create_thread.c			\
							command/info/info_channel.c				\
							command/info/info_team.c				\
							command/info/info_thread.c				\
							command/info/info_user.c				\
							command/list/list_channel.c				\
							command/list/list_comment.c				\
							command/list/list_team.c				\
							command/list/list_thread.c				\
							command/send/send_internal.c			\
							command/subscribed/subscribed_team.c	\
							command/subscribed/subscribed_user.c	\
							command/use/use_channel.c				\
							command/use/use_server.c				\
							command/use/use_team.c					\
							command/use/use_thread.c				\
							command/create.c						\
							command/help.c							\
							command/info.c							\
							command/list.c							\
							command/login.c							\
							command/logout.c						\
							command/messages.c						\
							command/send.c							\
							command/subscribe.c						\
							command/subscribed.c					\
							command/unsubscribe.c					\
							command/use.c							\
							command/user.c							\
							command/users.c							\
							comment/comment.c						\
							comment/comment_util.c					\
							exchange/exchange.c						\
							list/list.c								\
							list/list_node.c						\
							message/message.c						\
							message/message_util.c					\
							private/private.c						\
							server/server.c							\
							server/server_client.c					\
							server/server_client_io.c				\
							server/server_internal.c				\
							server/server_util.c					\
							server/server_util2.c					\
							subscriber/subscriber.c					\
							team/team.c								\
							team/team_util.c						\
							thread/thread.c							\
							thread/thread_util.c					\
							user/user.c								\
							user/user_util.c						\
							util/get_or_error.c						\
							util/string.c							\

TEST_SRC			=

CFLAGS				+=		-I $(INCL_DIR)
CFLAGS				+=		-W -Wall -Wextra -Werror

MAIN_OBJ			=		$(MAIN_SRC:%.c=$(OBJ_DIR)/%.o)

PROJ_OBJ			=		$(PROJ_SRC:%.c=$(OBJ_DIR)/%.o)

TEST_OBJ			=		$(TEST_SRC:%.c=$(OBJ_DIR)/%.o)

TEST_COV			=		$(PROJ_SRC:%.c=$(COV_DIR)/%.gcda)	\
							$(PROJ_SRC:%.c=$(COV_DIR)/%.gcno)	\
							$(TEST_SRC:%.c=$(COV_DIR)/%.gcda)	\
							$(TEST_SRC:%.c=$(COV_DIR)/%.gcno)	\

MAKEFLAGS			+=		--silent

NO_COLOR			=		\e[0;0m
GREEN_COLOR			=		\e[0;32m
RED_COLOR			=		\e[0;31m
GREEN_B_COLOR		=		\e[1;32m
RED_B_COLOR			=		\e[1;31m
YELLOW_B_COLOR		=		\e[1;33m

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(OBJ_DIR)/%.o:		$(TEST_DIR)/%.c
					mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@ \
					&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
					|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

$(NAME):			lib_socket lib_stdext $(MAIN_OBJ) $(PROJ_OBJ)
					$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

all:				$(NAME)

clean:
					$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

debug:				CFLAGS += -g3
debug:				all

debug_re:			CFLAGS += -g3
debug_re:			re

$(TEST_NAME):		CFLAGS += -fprofile-arcs -ftest-coverage
$(TEST_NAME):		LDLIBS += -lgcov -lcriterion
$(TEST_NAME):		$(PROJ_OBJ) $(TEST_OBJ)
					if [ -d $(TEST_DIR) ]; then \
						$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
						&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; } \
					fi

tests_run:			$(TEST_NAME)
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Unit tests not found$(NO_COLOR)"; \
					else \
						./$(TEST_NAME) \
						&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

tests_clean:		clean
					$(RM) $(TEST_OBJ)
					$(RM) $(TEST_COV)

tests_fclean:		tests_clean
					$(RM) $(TEST_NAME)

tests_re:			tests_fclean tests_run

tests_sh:			re
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(TEST_SH_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Functional tests not found$(NO_COLOR)"; \
					else \
						sh $(TEST_SH_NAME) $(NAME) \
						&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

lib_socket:
					cd $(LIB_SOCKET_DIR) && $(MAKE) lib_st

lib_socket_clean:
					cd $(LIB_SOCKET_DIR) && $(MAKE) lib_st_clean

lib_socket_fclean:
					cd $(LIB_SOCKET_DIR) && $(MAKE) lib_st_fclean

lib_socket_re:
					cd $(LIB_SOCKET_DIR) && $(MAKE) lib_st_re

lib_stdext:
					cd $(LIB_STDEXT_DIR) && $(MAKE) lib_st

lib_stdext_clean:
					cd $(LIB_STDEXT_DIR) && $(MAKE) lib_st_clean

lib_stdext_fclean:
					cd $(LIB_STDEXT_DIR) && $(MAKE) lib_st_fclean

lib_stdext_re:
					cd $(LIB_STDEXT_DIR) && $(MAKE) lib_st_re

full:				lib_socket lib_stdext all

full_clean:			lib_socket_clean lib_stdext_clean clean tests_clean

full_fclean:		lib_socket_fclean lib_stdext_fclean fclean tests_fclean

full_re:			lib_socket_re lib_stdext_re full_fclean full

.PHONY:				all clean fclean re													\
					debug debug_re														\
					tests_run tests_clean tests_fclean tests_re tests_sh				\
					lib_socket lib_socket_clean lib_socket_fclean lib_socket_re			\
					lib_stdext lib_stdext_clean lib_stdext_fclean lib_stdext_re			\
					full full_clean full_fclean full_re									\
