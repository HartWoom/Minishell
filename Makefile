##
## Makefile for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
## 
## Made by HartWoom
## Login   <antoine.hartwig@epitech.eu>
## 
## Started on  Mon Mar 20 10:20:30 2017 HartWoom
## Last update Wed Apr 12 13:42:26 2017 HartWoom
##

SRC	=	main.c					\
		pre_check.c				\
		cut_entry.c				\
		my_free_struct.c			\
		usefull/my_strlen_to.c			\
		usefull/my_put_exit.c			\
		usefull/my_strcp.c			\
		usefull/str_finder.c			\
		init/set_struct.c			\
		init/set_PATH.c				\
		init/set_HOME.c				\
		init/set_env.c				\
		my_builtins/my_builtins.c		\
		my_builtins/my_exit.c			\
		my_builtins/my_change_dir.c		\
		my_builtins/my_display_env.c		\
		my_builtins/my_setenv/my_setenv.c	\
		my_builtins/my_setenv/add_one.c		\
		my_builtins/my_unsetenv/my_unsetenv.c	\
		my_builtins/my_unsetenv/remove_one.c	\
		execute/execute_entry.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	mysh

CFLAGS	=	-Iinclude -W -Wall -Wextra -pedantic

LFLAGS	=	-Llib -lmy -lprintf -lgnl

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
