/*
** init.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Fri Mar 24 09:53:52 2017 HartWoom
** Last update Thu Mar 30 10:30:46 2017 HartWoom
*/

#ifndef INIT_H
# define INIT_H

#include <stdlib.h>
#include "struct.h"

char	**set_PATH(char **);
char	*set_HOME(char **);
char	**set_envp();
void	set_env(t_shell *, char **);
int	str_finder(char *, char *);
int	my_strlen_to_point(char *);

#endif
