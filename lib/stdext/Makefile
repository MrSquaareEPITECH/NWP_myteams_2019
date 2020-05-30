##
## EPITECH PROJECT, 2020
## EPI_stdext_2019
## File description:
## Makefile
##

NAME				=		a.out
LIB_NAME			=		libstdext.so
LIB_ST_NAME			=		libstdext.a
FUNC_TEST_NAME		=		tests/functional_tests.sh
UNIT_TEST_NAME		=		tests/unit_tests

COV_DIR				=		obj
INCL_DIR			=		include
OBJ_DIR				=		obj
SRC_DIR				=		src
TEST_DIR			=		tests

AR					=		ar rcs
CC					=		gcc
RM					=		rm -rf

MAIN_SRC			=		main.c

PROJ_SRC			=		array/arrdup.c						\
							array/arrfree.c						\
							array/arrlen.c						\
							memory/memdup.c						\
							string/strchrn.c					\
							string/strjoin.c					\
							string/strrchrn.c					\
							string/strrpbrk.c					\
							string/strpbrkn.c					\
							string/strrpbrkn.c					\
							string/strtrim.c					\
							string/strrtrim.c					\
							string/strltrim.c					\
							string/strsplit.c					\
							string/strsplitj.c					\
							string/strrem.c						\
							string/strrev.c						\
							string/strrstr.c					\
							string/strstrn.c					\
							string/strrstrn.c					\

TEST_SRC			=		array/test_arrlen.c					\
							array/test_arrdup.c					\
							array/test_arrfree.c				\
							memory/test_memdup.c				\
							string/test_strchrn.c				\
							string/test_strjoin.c				\
							string/test_strrchrn.c				\
							string/test_strrpbrk.c				\
							string/test_strpbrkn.c				\
							string/test_strrpbrkn.c				\
							string/test_strtrim.c				\
							string/test_strrtrim.c				\
							string/test_strltrim.c				\
							string/test_strsplit.c				\
							string/test_strsplitj.c				\
							string/test_strrem.c				\
							string/test_strrev.c				\
							string/test_strrstr.c				\
							string/test_strstrn.c				\
							string/test_strrstrn.c				\

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

$(NAME):			$(MAIN_OBJ) $(PROJ_OBJ)
					$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

all:				$(NAME)

clean:
					$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

tests_run:			unit_tests

debug:				CFLAGS += -g3
debug:				all

debug_re:			CFLAGS += -g3
debug_re:			re

$(LIB_NAME):		CFLAGS += -fPIC
$(LIB_NAME):		LDFLAGS += -shared
$(LIB_NAME):		$(PROJ_OBJ)
					$(CC) $(PROJ_OBJ) -o $(LIB_NAME) $(LDFLAGS) $(LDLIBS) \
					&& echo "$(GREEN_B_COLOR)$(LIB_NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(LIB_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib:				$(LIB_NAME)

lib_clean:
					$(RM) $(PROJ_OBJ)

lib_fclean:			lib_clean
					$(RM) $(LIB_NAME)

lib_re:				lib_fclean lib

$(LIB_ST_NAME):		$(PROJ_OBJ)
					$(AR) $(LIB_ST_NAME) $(PROJ_OBJ) \
					&& echo "$(GREEN_B_COLOR)$(LIB_ST_NAME) successfully created$(NO_COLOR)" \
					|| { echo "$(RED_B_COLOR)$(LIB_ST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib_st:				$(LIB_ST_NAME)

lib_st_clean:		lib_clean

lib_st_fclean:		lib_st_clean
					$(RM) $(LIB_ST_NAME)

lib_st_re:			lib_st_fclean lib_st

$(UNIT_TEST_NAME):	CFLAGS += -fprofile-arcs -ftest-coverage
$(UNIT_TEST_NAME):	LDLIBS += -lgcov -lcriterion
$(UNIT_TEST_NAME):	$(PROJ_OBJ) $(TEST_OBJ)
					if [ -d $(TEST_DIR) ]; then \
						$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(UNIT_TEST_NAME) $(LDFLAGS) $(LDLIBS) \
						&& echo "$(GREEN_B_COLOR)$(UNIT_TEST_NAME) successfully created$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)$(UNIT_TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; } \
					fi

unit_tests:			$(UNIT_TEST_NAME)
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(UNIT_TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Unit tests not found$(NO_COLOR)"; \
					else \
						./$(UNIT_TEST_NAME) \
						&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

unit_tests_clean:	clean
					$(RM) $(TEST_OBJ)
					$(RM) $(TEST_COV)

unit_tests_fclean:	unit_tests_clean
					$(RM) $(UNIT_TEST_NAME)

unit_tests_re:		unit_tests_fclean unit_tests

func_tests:			re
					if [ ! -d $(TEST_DIR) ] || [ ! -f $(FUNC_TEST_NAME) ]; then \
						echo "$(YELLOW_B_COLOR)Functional tests not found$(NO_COLOR)"; \
					else \
						sh $(FUNC_TEST_NAME) $(NAME) \
						&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
						|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; } \
					fi

func_tests_clean:	clean

func_tests_fclean:	fclean

func_tests_re:		func_tests_fclean func_tests

full:				all lib lib_st

full_clean:			clean lib_clean lib_st_clean unit_tests_clean func_tests_clean

full_fclean:		fclean lib_fclean lib_st_fclean unit_tests_fclean func_tests_fclean

full_re:			full_fclean full

.PHONY:				all clean fclean re													\
					debug debug_re														\
					lib lib_clean lib_fclean lib_re										\
					lib_st lib_st_clean lib_st_fclean lib_st_re							\
					unit_tests unit_tests_clean unit_tests_fclean unit_tests_re			\
					func_tests func_tests_clean func_tests_fclean func_tests_re			\
					full full_clean full_fclean full_re									\
