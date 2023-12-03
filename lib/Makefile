##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME		=	libmy.a

CPPFLAGS	=	-I./include/ -W -Wall -Wextra -Werror -g3

OBJS		=	$(SRCS:.c=.o)

LINKED		=	./linked_list/

SRCS		=	my_arraylen.c				\
				my_clean_str.c				\
				my_strcat.c					\
				my_str_to_array.c			\
				my_free_array.c				\
				$(LINKED)my_add_node.c		\
				$(LINKED)my_get_node.c		\
				$(LINKED)my_del_node.c		\
				$(LINKED)my_size_list.c 	\
				$(LINKED)my_free_list.c		\

all :	$(NAME)
$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) $(LINKED)*.gcno
	$(RM) $(LINKED)*.gcda
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY:	all clean fclean re
