/*
** setenv.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Fri Mar 31 11:38:29 2017 HartWoom
** Last update Fri Mar 31 11:42:36 2017 HartWoom
*/

#ifndef SETENV_H_
# define SETENV_H_

#include <unistd.h>
#include <stdlib.h>
#include "struct.h"
#include "usefull.h"

int	my_display_env(t_shell *);
int	str_finder(char *, char *);	

#endif
