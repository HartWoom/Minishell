/*
** my.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:06:39 2017 HartWoom
** Last update Fri Apr  7 09:53:48 2017 HartWoom
*/

#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"

# ifndef READ_SIZE
#  define READ_SIZE (21)
# endif /* !READ_SIZE */

void	set_struct(t_shell *, char **);
char	*get_next_line(const int);
int	my_strlen_to_space(char *);
char	**cut_entry(char *);
int	pre_check(t_shell *, char *);
int	my_builtins(t_shell *, char **);

#endif
