/*
** set_struct.c for shell in /home/hartwoom/Epitech/PSU_2016/PSU_2016_minishell2
** 
** Made by HartWoom
** Login   <antoine.hartwig@epitech.eu>
** 
** Started on  Mon Mar 20 10:10:41 2017 HartWoom
** Last update Mon Mar 20 14:48:59 2017 HartWoom
*/

#include "my.h"


void	set_struct(t_shell *shell, char **env)
{
  shell->PATH = set_PATH(env);
  shell->HOME = set_HOME(env);
}
