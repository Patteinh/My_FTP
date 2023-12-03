##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME		=	myftp

CPPFLAGS	=	-W -Wall -Wextra -Werror

CFLAGS		= 	-I./include/ -I$(LIB)include/

LFLAGS 		= 	-L $(LIB) -lmy

SRC_DIR		=	./src/

TEST_DIR	=	./tests/

LIB			=	./lib/

CMDFTP_DIR	=	$(SRC_DIR)cmd/
ENGFTP_DIR	=	$(SRC_DIR)engine/
TLSFTP_DIR	=	$(SRC_DIR)tools/

SRCS		=	$(SRC_DIR)main.c				\
				$(ENGFTP_DIR)myftp.c			\
				$(ENGFTP_DIR)new_connection.c	\
				$(ENGFTP_DIR)manage_client.c	\
				$(ENGFTP_DIR)remove_client.c	\
				$(ENGFTP_DIR)check_errors.c		\
				$(ENGFTP_DIR)set_ftp.c			\
				$(ENGFTP_DIR)free_ftp.c			\
				$(CMDFTP_DIR)user.c				\
				$(CMDFTP_DIR)pass.c				\
				$(CMDFTP_DIR)quit.c				\
				$(CMDFTP_DIR)cwd.c				\
				$(CMDFTP_DIR)cdup.c				\
				$(CMDFTP_DIR)pwd.c				\
				$(CMDFTP_DIR)pasv.c				\
				$(CMDFTP_DIR)port.c				\
				$(CMDFTP_DIR)retr.c				\
				$(CMDFTP_DIR)stor.c				\
				$(CMDFTP_DIR)list.c				\
				$(CMDFTP_DIR)dele.c				\
				$(CMDFTP_DIR)help.c				\
				$(CMDFTP_DIR)noop.c				\
				$(TLSFTP_DIR)tools_engine.c		\
				$(TLSFTP_DIR)tools_path.c		\

OBJS		=	$(SRCS:.c=.o)

VAL_TO		=	--track-origins=yes
VAL_SL		=	--show-leak-kinds=all
VAL_LC		=	--leak-check=full

all: $(NAME)
	@echo "Build ok!"

build_lib :
	make -C $(LIB)

$(NAME): build_lib $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LFLAGS)

debug: MAKE += -E CFLAGS+=-g3
debug: CPPFLAGS += -g3
debug: $(NAME)
	@echo "Build debug ok!"

tests_run:
	make -C $(TEST_DIR)
	@echo "Buld tests_run ok!"
	gcovr --html --html-details -o $(TEST_DIR)cov.html
	gcovr

clean:
	$(RM) $(OBJS)
	make clean -C $(LIB) -s
	make clean -C $(TEST_DIR) -s
	@echo "Clean ok!"

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIB) -s
	make fclean -C $(TEST_DIR) -s
	@echo "Fclean ok!"

re: fclean all

.PHONY: all build_lib debug tests_run clean fclean re
