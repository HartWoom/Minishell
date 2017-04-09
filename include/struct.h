/*
** struct.h for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Sun Apr  9 18:29:35 2017 HartWoom
** Last update Sun Apr  9 18:36:54 2017 HartWoom
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct s_shell
{
  char  **PATH;
  char  *HOME;
  char	**env;
  int	total_env;
  int	exit_status;
}       t_shell;

#endif
