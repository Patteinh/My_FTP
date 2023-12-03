##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME		=	unit_tests

CPPFLAGS	=	-W -Wall -Wextra -Werror

CFLAGS		= 	-I../include/ -I$(LIB)include/

LFLAGS 		= 	-L $(LIB) -lmy

LDFLAGS		=	--coverage -lcriterion

COVFLAGS	=	-lcriterion -lgcov

LIB			=	../lib/

SRC_DIR		=	../src/

ENGFTP_DIR	=	$(SRC_DIR)engine/

SRC_TESTS	=	$(ENGFTP_DIR)check_errors.c	\

UT_FILES	=	tests_check_errors.c		\

SRC_OBJS	=	$(SRC_TESTS:.c=.o)

UT_OBJS		=	$(UT_FILES:.c=.o)

all: $(NAME)
	@echo "Build ok!"

build_lib: MAKE += -E CFLAGS+=$(LDFLAGS)
build_lib:
	make -C $(LIB)

$(NAME) : build_lib
	$(CC) -c $(SRC_TESTS) $(CFLAGS) $(CPPFLAGS) $(LFLAGS) $(LDFLAGS)
	$(CC) -c $(UT_FILES) $(CFLAGS) $(CPPFLAGS) $(LFLAGS)
	$(CC) -o $(NAME) *.o $(CFLAGS) $(CPPFLAGS) $(LFLAGS) $(COVFLAGS)
	./$(NAME)

clean:
	$(RM) *.html
	$(RM) *.css
	$(RM) $(SRC_DIR)*.gcno
	$(RM) $(SRC_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcno
	$(RM) $(TEST_DIR)*.o
	$(RM) $(UT_OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB) -s

re: fclean all

.PHONY: all build_lib clean fclean re
