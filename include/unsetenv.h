/*
** unsetenv.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Apr  3 13:37:55 2017 HartWoom
** Last update Wed Apr  5 17:44:26 2017 HartWoom
*/

#ifndef UNSETENV_H_
# define UNSETENV_H

#include <stdlib.h>
#include <unistd.h>
#include "usefull.h"
#include "struct.h"

void	remove_one(t_shell *, char **, int, int);

#endif
