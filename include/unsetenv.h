/*
** unsetenv.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Apr  3 13:37:55 2017 HartWoom
** Last update Fri Apr  7 10:35:29 2017 HartWoom
*/

#ifndef UNSETENV_H_
# define UNSETENV_H

#include <stdlib.h>
#include <unistd.h>
#include "usefull.h"
#include "struct.h"

void	remove_one(t_shell *, int);
int	str_finder(char *, char *);

#endif
