##
## EPITECH PROJECT, 2019
## NWP_myteams_2019
## File description:
## Makefile
##

CLI_NAME			=		myteams_cli
SERVER_NAME			=		myteams_server

CLI_DIR				=		cli
SERVER_DIR			=		server

CP					=		cp
RM					=		rm -rf

MAKEFLAGS			+=		--silent

all:				cli server
					$(CP) $(CLI_DIR)/$(CLI_NAME) $(CLI_NAME)
					$(CP) $(SERVER_DIR)/$(SERVER_NAME) $(SERVER_NAME)

clean:				cli_clean server_clean

fclean:				cli_fclean server_fclean
					$(RM) $(CLI_NAME)
					$(RM) $(SERVER_NAME)

re:					fclean all

tests_run:			cli_tests_run server_tests_run

tests_sh:			cli_tests_sh server_tests_sh

cli:
					cd $(CLI_DIR) && $(MAKE) all

cli_clean:
					cd $(CLI_DIR) && $(MAKE) clean

cli_fclean:
					cd $(CLI_DIR) && $(MAKE) fclean

cli_re:				cli_fclean cli

cli_debug:
					cd $(CLI_DIR) && $(MAKE) debug

cli_debug_re:		cli_fclean cli_debug

cli_tests_run:
					cd $(CLI_DIR) && $(MAKE) tests_run

cli_tests_clean:
					cd $(CLI_DIR) && $(MAKE) tests_clean

cli_tests_fclean:
					cd $(CLI_DIR) && $(MAKE) tests_fclean

cli_tests_re:		cli_tests_fclean cli_tests_run

cli_tests_sh:
					cd $(CLI_DIR) && $(MAKE) tests_sh

server:
					cd $(SERVER_DIR) && $(MAKE) all

server_clean:
					cd $(SERVER_DIR) && $(MAKE) clean

server_fclean:
					cd $(SERVER_DIR) && $(MAKE) fclean

server_re:			server_fclean server

server_debug:
					cd $(SERVER_DIR) && $(MAKE) debug

server_debug_re:	server_fclean server_debug

server_tests_run:
					cd $(SERVER_DIR) && $(MAKE) tests_run

server_tests_clean:
					cd $(CLI_DIR) && $(MAKE) tests_clean

server_tests_fclean:
					cd $(CLI_DIR) && $(MAKE) tests_fclean

server_tests_re:	server_tests_fclean server_tests_run

server_tests_sh:
					cd $(SERVER_DIR) && $(MAKE) tests_sh

full:				all

full_clean:			clean cli_tests_clean server_tests_clean

full_fclean:		fclean cli_tests_fclean server_tests_fclean

full_re:			full_fclean full

full_debug:			cli_debug server_debug

full_debug_re:		full_fclean full_debug

.PHONY:				all clean fclean re																		\
					cli cli_clean cli_fclean cli_re cli_debug cli_debug_re									\
					cli_tests_run cli_tests_clean cli_tests_fclean cli_tests_re cli_tests_sh				\
					server server_clean server_fclean server_re server_debug server_debug_re				\
					server_tests_run server_tests_clean server_tests_fclean server_tests_re server_tests_sh	\
					full full_clean full_fclean full_re full_debug full_debug_re							\
