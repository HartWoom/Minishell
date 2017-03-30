/*
** my_builtins.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 23 16:53:28 2017 HartWoom
** Last update Fri Mar 24 10:24:23 2017 HartWoom
*/

#ifndef MY_BUILTINS_H
# define MY_BUILTINS_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"

int	my_change_dir(t_shell *, char **);
void	my_display_env(t_shell *);

#endif
