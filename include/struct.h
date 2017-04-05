/*
** struct.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Thu Mar 23 17:04:13 2017 HartWoom
** Last update Wed Apr  5 18:16:37 2017 HartWoom
*/

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_shell
{
  char  **PATH;
  char  *HOME;
  char	**env;
  int	total_env;
}       t_shell;

#endif
