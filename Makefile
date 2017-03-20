##
## Makefile for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
## 
## Made by HartWoom
## Login   <antoine.hartwig@epitech.eu>
## 
## Started on  Mon Mar 20 10:20:30 2017 HartWoom
## Last update Mon Mar 20 15:01:55 2017 HartWoom
##

SRC	=	main.c		\
		set_struct.c	\
		set_PATH.c	\
		set_HOME.c	\
		str_finder.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

NAME	=	mysh

CFLAGS	=	-Iinclude -W -Wall -Wextra -pedantic

LFLAGS	=	-Llib -lmy -lprintf

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
